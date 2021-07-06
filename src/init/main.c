// This file is a part of Maize Kernel
// Wrote by Ayush Yadav(clawbhaiya)
#include "drivers/framebuffer.h"
#include "drivers/tty/psf_parser.h"
#include "drivers/tty/tty.h"
#include "init/stivale2.h"

void kmain(struct stivale2_struct* bootinfo) {
    init_framebuffer(bootinfo);
    init_tty(bootinfo);
    init_colors(0x282828, 0xcc241d, 0x98971a, 0xd79921, 0x458588, 0xb16286,
                0x689d6a, 0xa89984, 0x928374, 0xfb4934, 0xb8bb26, 0xfabd2f,
                0x83a598, 0xd8369b, 0x8ec07c, 0xebdbb2);
    tty_puts("Maize Kernel x86_64");
}
