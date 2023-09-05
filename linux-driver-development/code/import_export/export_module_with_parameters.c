#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Muhammad Muneeb Yousaf");
MODULE_DESCRIPTION("Exported Kernel Module with Parameters");

static char *name = "world";
static int number = 3;

module_param(name, charp, S_IRUGO); // Accept a char pointer parameter
module_param(number, int, S_IRUGO); // Accept an integer parameter

EXPORT_SYMBOL(hello_kernel_module);

void hello_kernel_module(void) {
    printk(KERN_INFO "Hello, %s! The number is %d.\n", name, number);
}

static int __init export_module_init(void) {
    printk(KERN_INFO "Export module initialized.\n");
    return 0;
}

static void __exit export_module_exit(void) {
    printk(KERN_INFO "Export module removed.\n");
}

module_init(export_module_init);
module_exit(export_module_exit);

