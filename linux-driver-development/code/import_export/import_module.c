#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Muhammad Muneeb Yousaf");
MODULE_DESCRIPTION("Imported Kernel Module");

// Declare global variables as extern to access them from the exporting module
extern int my_integer;
extern char *my_string;

static int __init import_module_init(void) {
    printk(KERN_INFO "Import module initialized.\n");
    printk(KERN_INFO "my_integer: %d\n", my_integer);
    printk(KERN_INFO "my_string: %s\n", my_string);
    return 0;
}

static void __exit import_module_exit(void) {
    printk(KERN_INFO "Import module removed.\n");
}

module_init(import_module_init);
module_exit(import_module_exit);

