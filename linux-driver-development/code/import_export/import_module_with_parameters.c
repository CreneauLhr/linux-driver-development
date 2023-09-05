#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Imported Kernel Module with Parameters");

extern void hello_kernel_module(void); // Declare the external function

static char *custom_name = "openai";
static int custom_number = 42;

module_param(custom_name, charp, S_IRUGO); // Accept a char pointer parameter
module_param(custom_number, int, S_IRUGO); // Accept an integer parameter

static int __init import_module_init(void) {
    printk(KERN_INFO "Import module initialized.\n");
    hello_kernel_module(custom_name, custom_number); // Call the exported function with custom parameters
    return 0;
}

static void __exit import_module_exit(void) {
    printk(KERN_INFO "Import module removed.\n");
}

module_init(import_module_init);
module_exit(import_module_exit);

