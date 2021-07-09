#include <drivers/tty/psf_parser.h>
#include <stddef.h>

extern uint32_t _binary_scripts_zap_vga16_psf_start;
extern uint32_t _binary_scripts_zap_vga16_psf_end;

psf1_font font;

void init_psf()
{
    font.header = (psf1_header *)&_binary_scripts_zap_vga16_psf_start;
    font.glyphs = (void *)font.header + _binary_scripts_zap_vga16_psf_start;
}

psf1_font *get_font()
{
    return &font;
}
