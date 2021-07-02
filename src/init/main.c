// This file is a part of Maize Kernel
// Wrote by Ayush Yadav(clawbhaiya)
#include "init/stivale2.h"

void kmain(struct stivale2_struct* bootinfo) {
    struct stivale2_struct_tag_framebuffer* fb_tag =
        (struct stivale2_struct_tag_framebuffer*)stivale2_get_tag(
            bootinfo, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);

    for (uint64_t i = 0; i < 50; i++) {
        *(uint32_t*)(i + 100 * fb_tag->framebuffer_width +
                     fb_tag->framebuffer_addr) = 0xFFFFFF;
    }
}
