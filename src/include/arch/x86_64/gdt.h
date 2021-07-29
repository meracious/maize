#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>

typedef struct
{
    uint16_t limit0;
    uint16_t base0;
    uint8_t base1;
    uint8_t access_byte;
    uint8_t limit1;
    uint8_t base2;
} __attribute__((packed)) gdt_entry_t;

typedef struct
{
    uint16_t size;
    uint64_t offset;
} __attribute__((packed)) gdt_descriptor_t;

extern void load_gdt(gdt_descriptor_t *gdt);
void init_gdt();

#endif
