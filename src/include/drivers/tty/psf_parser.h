#ifndef __PSF_PARSER_H__
#define __PSF_PARSER_H__

#include <stdint.h>

#define PSF1_MAGIC0 0x36
#define PSF1_MAGIC1 0x04

typedef struct {
    uint8_t magic[2];
    uint8_t mode;
    uint8_t height;
} psf1_header;

typedef struct {
    psf1_header* header;
    void* glyphs;
} psf1_font;

void init_psf();
psf1_font* get_font();

#endif
