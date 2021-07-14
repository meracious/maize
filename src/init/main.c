#include <drivers/tty/tty.h>
#include <libk/utils.h>

/* function name: kmain
 * arguments: stivale2_struct*
 * returns: none
 */
void kmain(struct stivale2_struct *bootinfo)
{
    init_tty(bootinfo);
    init_colors(0x282828, 0xcc241d, 0x98971a, 0xd79921, 0x458588, 0xb16286,
        0x689d6a, 0xa89984, 0x928374, 0xfb4934, 0xb8bb26, 0xfabd2f,
        0x83a598, 0xd8369b, 0x8ec07c, 0xebdbb2);
    fetch();
}
