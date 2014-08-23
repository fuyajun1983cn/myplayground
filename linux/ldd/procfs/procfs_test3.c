#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/sched.h> //for current

//Entries for /proc/gdl and /proc/gdl/memory
static struct proc_dir_entry *mm_proc_mem;
static struct proc_dir_entry *mm_proc_dir;

//only output some info from kernel

static int procfs_test3_show(struct seq_file *m, void *v)
{
	seq_printf(m, "Current Pid: %d\n", current->pid);
	seq_printf(m, "Current Process Name: %s\n", current->comm);
	return 0;
}

static int procfs_test3_open(struct inode *inode, struct file *file)
{
	return single_open(file, procfs_test3_show, NULL);
}

static const struct file_operations procfs_test3_fops = {
	.open           = procfs_test3_open,
	.read           = seq_read,
	.llseek         = seq_lseek,
	.release        = seq_release,
};

static int __init procfs_test3_init(void)
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
    mm_proc_mem = proc_create("memory", S_IFREG|S_IRWXU|S_IRWXG|S_IRWXO, mm_proc_dir, &procfs_test3_fops);
    if (mm_proc_mem == 0) {
        printk(KERN_ERR "/proc/gdl/memory creation failed\n");
        proc_remove(mm_proc_dir);
        mm_proc_dir = 0;
        return -1;
    }

    return 0;
}

static void __exit procfs_test3_exit(void)
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
module_init(procfs_test3_init);
module_exit(procfs_test3_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yajun Fu<fuyajun1983cn@163.com");
