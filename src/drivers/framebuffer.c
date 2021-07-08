#include <drivers/framebuffer.h>
#include <init/stivale2.h>
#include <stddef.h>
#include <stdint.h>

fb_info_t fb_info;

/* function name: init_framebuffer
 * arguments: stivale2_struct*
 * returns: nothing
 */
void init_framebuffer(struct stivale2_struct *bootinfo)
{
    struct stivale2_struct_tag_framebuffer *fb =
        (struct stivale2_struct_tag_framebuffer *)stivale2_get_tag(
            bootinfo, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
    fb_info.address = (uint32_t *)(uint64_t)fb->framebuffer_addr;
    fb_info.width = fb->framebuffer_width;
    fb_info.height = fb->framebuffer_height;
    fb_info.bpp = fb->framebuffer_bpp;
}

/* function name: fb_get_info
 * arguments: nothing
 * returns: struct fb_info_t
 */
fb_info_t *get_fb_info()
{
    return &fb_info;
}

/* function name: fb_plot_pixel
 * arguments: unit32_t x position, uint32_t y position, uitn32_t color code of
 * pixel returns: nothing
 */
void fb_plot_pixel(uint32_t x_pos, uint32_t y_pos, uint32_t color)
{
    *(uint32_t *)(x_pos + y_pos * fb_info.width + fb_info.address) = color;
}

void fb_clear(uint32_t color)
{
    for (size_t i = 0; i < fb_info.width * fb_info.height; i++)
    {
        fb_info.address[i] = color;
    }
}
