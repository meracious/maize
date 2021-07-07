/*
Copyright© Ayush Yadav 2021 under MIT License.
Hobby ANSI Parser(HANSIP) is forked from VTConsole, made by
https://github.com/sleepy-monax HANSIP is a modified version of VTConsole. But
instead of a terminal, it is a ANSI Parser only.
*/
#include "drivers/tty/hansi_parser.h"
#include "drivers/tty/tty.h"

hansi_parser g_parser = {.state = HTERM_ESC,
                         .index = 0};  // global parser object

bool isdigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

void hansi_handle_sgr(ansi_args* stack, int count) {
    static bool fg_bold = false;
    static bool bg_bold = false;
    for (int i = 0; i < count; i++) {
        if (stack[i].empty || stack[i].value == 0) {
            set_currentFg(colors[7]);
            set_currentBg(colors[0]);
            fg_bold = false;
            bg_bold = false;
        } else {
            int attr = stack[i].value;
            int value;
            if (attr == 1) {
                fg_bold = true;
            } else if (attr == 21) {
                bg_bold = true;
            } else if (attr >= 30 && attr <= 37) {
                if (fg_bold)
                    value = (attr - 30) + 8;
                else
                    value = attr - 30;
                set_currentFg(colors[value]);
            } else if (attr >= 40 && attr <= 47) {
                if (bg_bold)
                    value = (attr - 40) + 8;
                else
                    value = attr - 40;
                set_currentBg(colors[value]);
            }
        }
    }
}

void hansi_handler(char c) {
    if (g_parser.state == HTERM_ESC) {
        if (c == '\033') {
            g_parser.state = HTERM_BRACKET;
            g_parser.index = 0;
            g_parser.args[g_parser.index].value = 0;
            g_parser.args[g_parser.index].empty = true;
        } else {
            g_parser.state = HTERM_ESC;
            tty_putchar_raw(c);
        }
    } else if (g_parser.state == HTERM_BRACKET) {
        if (c == '[') {
            g_parser.state = HTERM_ARGS;
        } else {
            g_parser.state = HTERM_ESC;
            tty_putchar_raw(c);
        }
    } else if (g_parser.state == HTERM_ARGS) {
        if (isdigit(c)) {
            g_parser.args[g_parser.index].value *= 10;
            g_parser.args[g_parser.index].value += (c - '0');
            g_parser.args[g_parser.index].empty = false;
        } else {
            if (g_parser.index < MAX_ARGS)
                g_parser.index++;
            g_parser.args[g_parser.index].value = 0;
            g_parser.args[g_parser.index].empty = true;
            g_parser.state = HTERM_ENDARGS;
        }
    }
    if (g_parser.state == HTERM_ENDARGS) {
        if (c == ';') {
            g_parser.state = HTERM_ARGS;
        } else {
            switch (c) {
                case 'm':
                    hansi_handle_sgr(&g_parser.args[0], g_parser.index);
                    break;
                default:
                    break;
            }
            g_parser.state = HTERM_ESC;
        }
    }
}
