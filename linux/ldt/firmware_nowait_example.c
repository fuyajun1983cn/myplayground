#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/string.h>
#include <linux/firmware.h>
#include <linux/slab.h>     /* kfree */

static void
sample_firmware_load(const char *firmware, int size)
{
  u8 *buf = kmalloc(size + 1, GFP_KERNEL);
  memcpy(buf, firmware, size);
  buf[size] = '\0';
  printk(KERN_INFO "firmware_example: Firmware: %s\n", buf);
  kfree(buf);
}

static void
sample_probe_async_cont(const struct firmware *fw, void *context)
{
  if (!fw) {
    printk(KERN_ERR "firmware_nowait_example: Firmware not available\n");
    return;
  }

  printk(KERN_INFO "firmware_nowait_example: Device Pointer \"%s\"\n",
         (char*)context);
  sample_firmware_load(fw->data, fw->size);
}

static void
sample_probe_async(struct device *dev)
{
  /* Let's say I cann't sleep */
  int error;
  printk(KERN_INFO "firmware_example: ghost device inserted\n");
  error = request_firmware_nowait(THIS_MODULE, FW_ACTION_NOHOTPLUG,
                                  "sample_firmware.bin", dev,GFP_KERNEL,
                                  "my device pointer", sample_probe_async_cont);
  if (error) {
    printk(KERN_ERR "firmware_nowait_example: request_firmware_nowait Failed\n");
  }
}

static void
ghost_release(struct device *dev)
{
  printk(KERN_DEBUG "firmware_nowait_example: ghost device released\n");
}

static struct device ghost_device = {
  .init_name = "ghost0",
  .release = ghost_release
};

static int __init sample_init(void)
{
  device_register(&ghost_device);
  sample_probe_async(&ghost_device);
  return 0;
}

static void __exit sample_exit(void)
{
  device_unregister(&ghost_device);
}

module_init(sample_init);
module_exit(sample_exit);

MODULE_LICENSE("GPL");
