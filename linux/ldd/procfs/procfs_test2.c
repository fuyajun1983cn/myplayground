#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

/**
*     Seq file test
*/
//Entries for /proc/gdl and /proc/gdl/memory
static struct proc_dir_entry *mm_proc_mem;
static struct proc_dir_entry *mm_proc_dir;

//only to how at most 10 characters
#define MAX_COUNT  10

unsigned char strings[80];

static ssize_t procfs_test2_write(struct file * file, 
                              const char  __user * buffer, 
                              size_t count, 
                              loff_t *        data)
{
	size_t   size_to_copy;
	size_to_copy = count;
	memset(strings, 0x0, 80);
	copy_from_user(strings, buffer, size_to_copy);
	printk("%s", strings);
	return size_to_copy;
}

static void  *procfs_test2_seq_start(struct seq_file *f, loff_t *pos)
{
	return (*pos < MAX_COUNT) ? pos : NULL;
}

static void  *procfs_test2_seq_next(struct seq_file *f, void *v, loff_t *pos)
{
	printk("current pos: %d\n", (int)(*pos));
	(*pos)++;
	if (*pos >= MAX_COUNT)
		return NULL;
	return pos;
}

static void  procfs_test2_seq_stop(struct seq_file *f, void *v)
{
	/* Nothing to do */
}

static int  procfs_test2_show(struct seq_file *pi, void *v)
{
	unsigned int i = *(loff_t *) v;
	seq_putc(pi, strings[i]);
	return 0;
}

static const struct seq_operations procfs_test2_seq_ops = {
	.start = procfs_test2_seq_start,
	.next  = procfs_test2_seq_next,
	.stop  = procfs_test2_seq_stop,
	.show  = procfs_test2_show
};

static int  procfs_test2_open(struct inode *inode, struct file *filp)
{
	return seq_open(filp, &procfs_test2_seq_ops);
}

static const struct file_operations procfs_test2_fops = {
	.open           = procfs_test2_open,
	.read           = seq_read,
	.llseek         = seq_lseek,
	.release        = seq_release,
	.write         = procfs_test2_write,
};

static int __init procfs_test2_init(void)
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
    mm_proc_mem = proc_create("memory", S_IFREG|S_IRWXU|S_IRWXG|S_IRWXO, mm_proc_dir, &procfs_test2_fops);
    if (mm_proc_mem == 0) {
        printk(KERN_ERR "/proc/gdl/memory creation failed\n");
        proc_remove(mm_proc_dir);
        mm_proc_dir = 0;
        return -1;
    }

    return 0;
}

static void __exit procfs_test2_exit(void)
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
module_init(procfs_test2_init);
module_exit(procfs_test2_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yajun Fu<fuyajun1983cn@163.com");
