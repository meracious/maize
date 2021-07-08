#include <drivers/tty/psf_parser.h>
#include <stddef.h>

extern uint32_t _binary_scripts_zap_vga16_psf_start;
extern uint32_t _binary_scripts_zap_vga16_psf_end;

psf1_font font;

void init_psf()
{
    psf1_header *header = (psf1_header *)&_binary_scripts_zap_vga16_psf_start;
    void *glyphs = (void *)(header + _binary_scripts_zap_vga16_psf_start);
    font.header = header;
    font.glyphs = glyphs;
}

psf1_font *get_font()
{
    return &font;
}
