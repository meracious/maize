#include "drivers/framebuffer.h"
#include "drivers/tty/psf_parser.h"
#include "stddef.h"

extern uint32_t _binary_scripts_zap_vga16_psf_start;
extern uint32_t _binary_scripts_zap_vga16_psf_end;

psf1_font font;

/* function name: init_psf
 * arguments: nothing
 * returns: nothing
 */
void init_psf()
{
    font.header = (psf1_header *)&_binary_scripts_zap_vga16_psf_start;
    font.glyphs = (void *)(font.header + _binary_scripts_zap_vga16_psf_start);
}
/* function name: get_font
 * arguments: nothing
 * returns: psf font
 */
psf1_font *get_font()
{
    return &font;
}

/* function name: psf_putchar
 * arguments: char to print
 * returns: nothing
 */
void psf_putchar(char c, uint64_t xoff, uint64_t yoff)
{
    char *font_ptr = (char *)font.glyphs + (c * font.header->height);
    for (uint64_t y = yoff; y < yoff + 16; y++)
    {
        for (uint64_t x = xoff; x < xoff + 8; x++)
        {
            if ((*font_ptr & (0b10000000 >> (x - xoff))) > 0)
            {
                fb_plot_pixel(x, y, 0xffffff);
            }
        }
    }
}
