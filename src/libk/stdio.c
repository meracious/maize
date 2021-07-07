#include <drivers/tty/tty.h>
#include <libk/stdio.h>
#include <libk/string.h>

void putchar(char c) {
    tty_putchar(c);
}

void puts(const char* str) {
    while (*str != 0) {
        putchar(*str);
        str++;
    }
}

int __vsprintf__(char* fmt,
                 va_list args,
                 void (*putchar_func)(char c),
                 void (*puts_func)(const char* str)) {
    int integer;
    uint64_t unsigned_long;
    uint32_t unsigned_int;
    uint16_t unsigned_short;
    uint8_t unsigned_char;
    char character;
    char* str = NULL;

    while (*fmt != 0) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
                case 'c':
                    character = va_arg(args, int);
                    putchar_func(character);
                    break;
                case 's':
                    str = va_arg(args, char*);
                    puts_func(str);
                    break;
                case 'd':
                case 'i':
                    integer = va_arg(args, int);
                    itoa(integer, str, 10);
                    puts_func(str);
                    break;
                case 'x':
                    fmt++;
                    if (*fmt == 'l') {
                        unsigned_long = va_arg(args, uint64_t);
                        utoa(unsigned_long, str, 16);
                        puts_func(str);
                    } else if (*fmt == 'i') {
                        unsigned_int = va_arg(args, uint32_t);
                        utoa((uint64_t)unsigned_int, str, 16);
                        puts_func(str);
                    } else if (*fmt == 's') {
                        unsigned_short = va_arg(args, int);
                        utoa((uint64_t)unsigned_short, str, 16);
                        puts_func(str);
                    } else if (*fmt == 'd') {
                        integer = va_arg(args, int);
                        itoa(integer, str, 16);
                        puts_func(str);
                    } else if (*fmt == 'c') {
                        character = va_arg(args, int);
                        itoa((int)character, str, 16);
                        puts_func(str);
                    } else if (*fmt == 'h') {
                        unsigned_char = va_arg(args, int);
                        utoa((uint64_t)unsigned_char, str, 16);
                        puts_func(str);
                    } else
                        putchar_func(*fmt);
                    break;
                case 'u':
                    fmt++;
                    if (*fmt == 'l') {
                        unsigned_long = va_arg(args, uint64_t);
                        utoa(unsigned_long, str, 10);
                        puts_func(str);
                    } else if (*fmt == 'i') {
                        unsigned_int = va_arg(args, uint32_t);
                        utoa((uint64_t)unsigned_int, str, 10);
                        puts_func(str);
                    } else if (*fmt == 's') {
                        unsigned_short = va_arg(args, int);
                        utoa((uint64_t)unsigned_short, str, 10);
                        puts_func(str);
                    } else if (*fmt == 'h') {
                        unsigned_char = va_arg(args, int);
                        utoa((uint64_t)unsigned_char, str, 10);
                        puts_func(str);
                    } else
                        putchar_func(*fmt);
                    break;
                default:
                    putchar_func(*fmt);
                    break;
            }
        } else {
            putchar_func(*fmt);
        }
        fmt++;
    }
    return 0;
}

int printf(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    __vsprintf__(fmt, args, putchar, puts);
    va_end(args);
    return 0;
}
