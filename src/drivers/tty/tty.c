#include <drivers/framebuffer.h>
#include <drivers/tty/font.h>
#include <drivers/tty/hansi_parser.h>
#include <drivers/tty/tty.h>

fb_info_t *fb = NULL;

uint32_t cx, cy;
uint32_t colors[16];

uint32_t currentFg, currentBg;

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
    uint32_t whiteBright)
{
    // normal colors
    colors[0] = black;
    colors[1] = red;
    colors[2] = green;
    colors[3] = yellow;
    colors[4] = blue;
    colors[5] = purple;
    colors[6] = cyan;
    colors[7] = white;

    // bright colors
    colors[8] = blackBright;
    colors[9] = redBright;
    colors[10] = greenBright;
    colors[11] = yellowBright;
    colors[12] = blueBright;
    colors[13] = purpleBright;
    colors[14] = cyanBright;
    colors[15] = whiteBright;

    currentBg = colors[0];
    currentFg = colors[7];
    fb_clear(currentBg);
}

void init_tty(struct stivale2_struct *bootinfo)
{
    init_framebuffer(bootinfo);
    fb = get_fb_info();
    cx = 0;
    cy = 0;
}

void tty_paint_cell(cell_t cell)
{
    uint8_t iy, ix;
    for (iy = 0; iy < 8; iy++)
    {
        for (ix = 0; ix < 8; ix++)
        {
            // paint the background of cell
            if ((font[128][iy] >> ix) & 1)
            {
                fb_plot_pixel(ix + cx * GLYPH_WIDTH, iy + cy * GLYPH_HEIGHT,
                    cell.bg);
            }

            // paint the foreground of cell
            if ((font[(uint8_t)cell.c][iy] >> ix) & 1)
            {
                fb_plot_pixel(ix + cx * GLYPH_WIDTH, iy + cy * GLYPH_HEIGHT,
                    cell.fg);
            }
        }
    }
}

void tty_putchar_raw(char c)
{
    switch (c)
    {
    case '\n':
        cx = 0;
        cy++;
        break;
    case '\r':
        cx = 0;
        break;
    case '\t':
        cx = cx - (cx % 8) + 8;
        break;
    case '\b':
        cx--;
        tty_putchar_raw(' ');
        cx--;
        break;
    default:
    {
        cell_t cell = {.c = c, .fg = currentFg, .bg = currentBg};
        tty_paint_cell(cell);
        cx += 1;
    }
    }
    if (cx >= fb->width / GLYPH_WIDTH)
    {
        cx = 0;
        cy++;
    }
}

void tty_putchar(char c)
{
    hansi_handler(c);
}

void tty_puts(char *str)
{
    while (*str != 0)
    {
        tty_putchar(*str);
        str++;
    }
}

void set_currentBg(uint32_t color)
{
    currentBg = color;
}

void set_currentFg(uint32_t color)
{
    currentFg = color;
}
