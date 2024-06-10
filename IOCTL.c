#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)
int32_t value = 0;
dev_t dev = 0;
MODULE_LICENSE("GPL");

ssize_t eg_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "In function %s\n",__FUNCTION__);
	return 0;
}

ssize_t eg_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	
	printk(KERN_ALERT "In function %s\n",__FUNCTION__);
	return length;
}

int eg_open (struct inode *pinode, struct file *pfile)
{

	printk(KERN_ALERT "In function %s\n",__FUNCTION__);
	return 0;
}

int eg_release (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "In function %s\n",__FUNCTION__);
	return 0;
}

long eg_ioctl (struct file *file, unsigned int cmd, unsigned long arg)
{
	printk(KERN_ALERT "In function %s\n",__FUNCTION__);
	switch(cmd)
	{
		case WR_VALUE:
			if(copy_from_user(&value ,(int32_t*) arg, sizeof(value)))
			{
				printk(KERN_ALERT"DATA  WRITE : Err!!\n");
	
			}
			printk(KERN_ALERT"Value = %d\n",value);
			break;
		case RD_VALUE:
			if( copy_to_user((int32_t*) arg, &value, sizeof(value)))
			{
				printk(KERN_ALERT"DATA READ : Err!\n");
			}
			break;
		default:
			printk(KERN_ALERT"DEFAULT\n");
			break;
	}
	return 0;
}


struct file_operations eg_file_operations = {
	.owner = THIS_MODULE,
	.open = eg_open,
	.read = eg_read,
	.write = eg_write,
       .release = eg_release,
       .unlocked_ioctl = eg_ioctl,
};

MODULE_LICENSE("GPL");

int __init  ex_module_init(void)
{
	printk(KERN_ALERT "ex_module_init function\n");
	//Register a chara device
	register_chrdev(200,"eg_device",&eg_file_operations); //200 is the major number check with /proc/devices
	return 0;
}

void ex_module_exit(void)
{
	printk(KERN_ALERT "Exit\n");
	unregister_chrdev(200,"eg_device");
}

module_init(ex_module_init);
module_exit(ex_module_exit);


