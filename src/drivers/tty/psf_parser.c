#include <drivers/tty/psf_parser.h>
#include <stddef.h>

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
    font.glyphs = (void *)font.header + _binary_scripts_zap_vga16_psf_start;
}
/* function name: get_font
 * arguments: nothing
 * returns: psf font
 */
psf1_font *get_font()
{
    return &font;
}
