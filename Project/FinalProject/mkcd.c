#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/stat.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>

extern long do_mkcd(const char __user *pathname)
{
  long make;
	long chdir;
	printk("Starting mkcd\n");

	make = ksys_mkdir(pathname, 0777);
	if (make < 0)
	{
		printk("Error making directory %s\n", pathname);
		return -1;
	}
	printk("Made new directory %s\n", pathname);

	chdir = ksys_chdir(pathname);
	if (chdir < 0)
	{
		printk("Error changing into directory %s\n", pathname);
		return -1;
	}
	printk("Changed into new directory %s\n", pathname);
	return 0;
}

SYSCALL_DEFINE1(mkcd, const char __user *, pathname)
{
  return do_mkcd(pathname);
}
