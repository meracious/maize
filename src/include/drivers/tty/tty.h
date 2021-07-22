#ifndef __TTY_H__
#define __TTY_H__

#include <drivers/tty/tty.h>
#include <init/stivale2.h>
#include <stddef.h>
#include <stdint.h>

typedef struct
{
    char c;
    uint32_t fg;
    uint32_t bg;
} cell_t;

extern uint32_t colors[16];

void init_tty(struct stivale2_struct *bootinfo);
void init_colors(uint32_t black,
    uint32_t red,
    uint32_t green,
    uint32_t yellow,
    uint32_t blue,
    uint32_t purple,
    uint32_t cyan,
    uint32_t white,
    uint32_t blackBright,
    uint32_t redBright,
    uint32_t greenBright,
    uint32_t yellowBright,
    uint32_t blueBright,
    uint32_t purpleBright,
    uint32_t cyanBright,
    uint32_t whiteBright);

void tty_putchar_raw(char c);
void tty_putchar(char c);
void tty_puts(char *str);

void set_currentFg(uint32_t color);
void set_currentBg(uint32_t color);

#endif
