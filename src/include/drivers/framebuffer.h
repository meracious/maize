#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

#include <init/stivale2.h>

typedef struct {
    uint32_t* address;
    uint32_t width;
    uint32_t height;
    uint32_t bpp;
} fb_info_t;

void init_framebuffer(struct stivale2_struct* bootinfo);
void fb_plot_pixel(uint32_t x_pos, uint32_t y_pos, uint32_t color);
fb_info_t* get_fb_info();
void fb_clear(uint32_t color);

#endif
