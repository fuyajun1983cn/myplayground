#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>

/* Device structure */
static struct platform_device *example_dev; 

static int foo = 0;
static int baz = 0;
static int bar = 0;

/*
 * The "foo" file where a static variable is read from and written to.
 */
static ssize_t show(struct kobject *kobj, struct kobj_attribute *attr,
			char *buf)
{
	int var;
	if (!strcmp(attr->attr.name, "foo") ){
		var = foo;
	} else if (!strcmp(attr->attr.name, "baz")) {
		var = baz;
	} else if (!strcmp(attr->attr.name, "bar")) {
		var = bar;
	} else {
		return 0;
	}
	return sprintf(buf, "%d\n", var);
}

static ssize_t store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	int var;
	sscanf(buf, "%du", &var);
	if (!strcmp(attr->attr.name, "foo")) {
		foo = var;
	} else if (!strcmp(attr->attr.name, "baz")) {
		baz = var;
	} else if (!strcmp(attr->attr.name, "bar") ){
		bar = var;
	} else {
		return 0;
	}
	return count;
}

static struct kobj_attribute foo_attribute = 
	__ATTR(foo, 0666, show, store);
static struct kobj_attribute bar_attribute = 
	__ATTR(bar, 0666, show, store);
static struct kobj_attribute baz_attribute = 
	__ATTR(baz, 0666, show, store);

/*
 * Create a group of attributes so that we can create and destroy them all
 * at once.
 */
static struct attribute *attrs[] = {
	&foo_attribute.attr,
	&bar_attribute.attr,
	&baz_attribute.attr,
	NULL,	/* need to NULL terminate the list of attributes */
};

/*
 * An unnamed attribute group will put all of the attributes directly in
 * the kobject directory.  If we specify a name, a subdirectory will be
 * created for the attributes with the directory being the name of the
 * attribute group.
 */
static struct attribute_group example_attr_group = {
//	.name = "fuyajun",
	.attrs = attrs,
};

static int __init  sysfs_test_init(void)
{
	int retval = -1;
	/* Register a platform device */
	example_dev = platform_device_register_simple("example", -1, NULL, 0);
	if (IS_ERR(example_dev)) {
		PTR_ERR(example_dev);
		printk("sysfs_test_init: error\n");
		return retval;
	}

	/* Create a sysfs node to read simulated coordinates */
	retval = sysfs_create_group(&example_dev->dev.kobj, &example_attr_group);
	return retval;
}

static void __exit sysfs_test_exit(void)
{
	/* Cleanup sysfs node */
	sysfs_remove_group(&example_dev->dev.kobj, &example_attr_group);
	/* Unregister driver */
	platform_device_unregister(example_dev);
}

module_init(sysfs_test_init);
module_exit(sysfs_test_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yajun Fu <fuyajun1983cn@163.com>");

