/*
  * read_file.c - A Module to read a file from Kernel Space
  */
 #include <linux/module.h>
 #include <linux/fs.h>

 #define PATH "/home/fuyajun/.bash_history"
 int mod_init(void)
 {
       struct file *fp;
       char buf[512];
       int offset = 0;
       int ret, i;


       /*open the file in read mode*/
       fp = filp_open(PATH, O_RDONLY, 0);
       if (IS_ERR(fp)) {
            printk("Cannot open the file %ld\n", PTR_ERR(fp));
            return -1;
       }

       printk("Opened the file successfully\n");
       /*Read the data to the end of the file*/
       while (1) {
            ret = kernel_read(fp, offset, buf, 512);
            if (ret > 0) {
                    for (i = 0; i < ret; i++)
                            printk("%c", buf[i]);
                    offset += ret;
            } else
                    break;
        }

       filp_close(fp, NULL);
       return 0;
  }

  void mod_exit(void)
  {

  }

  module_init(mod_init); 
  module_exit(mod_exit);

 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("Jackson Fu(fuyajun1983cn@163.com");
 MODULE_DESCRIPTION("Module to read a file from kernel space");    
