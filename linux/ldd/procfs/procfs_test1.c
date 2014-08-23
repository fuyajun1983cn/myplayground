#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

//Entries for /proc/gdl and /proc/gdl/memory
static struct proc_dir_entry *mm_proc_mem;
static struct proc_dir_entry *mm_proc_dir;

static ssize_t procfs_test1_write(struct file * file, 
                              const char  __user * buffer, 
                              size_t count, 
                              loff_t *        data)
{
	unsigned char file_name[80];
	size_t   size_to_copy;
	size_to_copy = count;
	memset(file_name, 0x0, 80);
	copy_from_user(file_name, buffer, size_to_copy);
	printk("%s", file_name);
	return size_to_copy;
}

static const struct file_operations procfs_test1_fops = {
//	.open		= procfs_test1_open,
//	.read		= seq_read,
//	.llseek		= seq_lseek,
//	.release	= single_release,
	.write = procfs_test1_write,
};

static int __init procfs_test1_init(void)
{
    mm_proc_dir = 0;
    mm_proc_mem = 0;

    //create a directory under /proc
    mm_proc_dir = proc_mkdir("gdl", 0);
    if (mm_proc_dir == 0) {
        printk(KERN_ERR "/proc/gdl/ creation failed\n");
	return -1;
    }

    //create /proc/gdl/memory file
    mm_proc_mem = proc_create("memory", S_IFREG|S_IRWXU|S_IRWXG|S_IRWXO, mm_proc_dir, &procfs_test1_fops);
    if (mm_proc_mem == 0) {
        printk(KERN_ERR "/proc/gdl/memory creation failed\n");
        proc_remove(mm_proc_dir);
        mm_proc_dir = 0;
        return -1;
    }

    return 0;
}

static void __exit procfs_test1_exit(void)
{
   if (mm_proc_dir != 0)
    {
        if (mm_proc_mem != 0)
        {
            proc_remove(mm_proc_mem);
            mm_proc_mem = 0;
        }

        proc_remove(mm_proc_dir);
        mm_proc_dir = 0;
    }
}
module_init(procfs_test1_init);
module_exit(procfs_test1_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yajun Fu<fuyajun1983cn@163.com");
