#include "device_file.h"
#include <linux/init.h>       /* module_init, module_exit */
#include <linux/module.h> /* version info, MODULE_LICENSE, MODULE_AUTHOR, printk() */

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Swapnil Haria, Wisconsin");


/*===============================================================================================*/
static int simple_driver_init(void)
{
      int result = 0;
    printk( KERN_NOTICE "gem5-accel-driver: Initialization started" );

      result = register_device();
    return result;
}
/*-----------------------------------------------------------------------------------------------*/
static void simple_driver_exit(void)
{
   printk( KERN_NOTICE "gem5-accel-driver: Exiting" );
    unregister_device();
}
/*===============================================================================================*/

module_init(simple_driver_init);
module_exit(simple_driver_exit);
