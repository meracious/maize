#include "drivers/tty/tty.h"
#include "libk/utils.h"

/* function name: kmain
 * arguments: stivale2_struct*
 * returns: none
 */
void kmain(struct stivale2_struct *bootinfo)
{
    init_arg_parser(bootinfo);
    init_tty(bootinfo);
    fetch();
    print_args();
}
