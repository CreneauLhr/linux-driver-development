#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Muhammad Muneeb Yousaf");
MODULE_DESCRIPTION("Exported Kernel Module");

// Declare global variables that will store the values to be passed
static int my_integer = 0;
static char *my_string = "DefaultString";

// Export the global variables
EXPORT_SYMBOL(my_integer);
EXPORT_SYMBOL(my_string);

static int __init export_module_init(void) {
    printk(KERN_INFO "Export module initialized.\n");
    my_integer = 42;             // Set an integer value
    my_string = "Hello, world";  // Set a string value
    return 0;
}

static void __exit export_module_exit(void) {
    printk(KERN_INFO "Export module removed.\n");
}

module_init(export_module_init);
module_exit(export_module_exit);

