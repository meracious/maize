#include "libk/string.h"

char *itoa(int value, char *str, int base)
{
    char *rc;
    char *ptr;
    char *low;
    if (base < 2 || base > 36)
    {
        *str = '\0';
        return str;
    }
    rc = ptr = str;
    if (value < 0 && base == 10)
    {
        *ptr++ = '-';
    }
    low = ptr;
    do
    {
        *ptr++ =
            "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstu"
            "vwxyz"[35 + value % base];
        value /= base;
    } while (value);
    *ptr-- = '\0';
    while (low < ptr)
    {
        char temp = *low;
        *low++ = *ptr;
        *ptr-- = temp;
    }
    return rc;
}

char *utoa(uint64_t value, char *str, uint8_t base)
{
    char *rc;
    char *ptr;
    char *low;
    if (base < 2 || base > 36)
    {
        *str = '\0';
        return str;
    }
    rc = ptr = str;
    low = ptr;
    do
    {
        *ptr++ =
            "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstu"
            "vwxyz"[35 + value % base];
        value /= base;
    } while (value);
    *ptr-- = '\0';
    while (low < ptr)
    {
        char temp = *low;
        *low++ = *ptr;
        *ptr-- = temp;
    }
    return rc;
}

void *memset(void *bufptr, int value, size_t size)
{
    unsigned char *buf = (unsigned char *)bufptr;
    for (size_t i = 0; i < size; i++)
        buf[i] = (unsigned char)value;
    return bufptr;
}

uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count)
{
    uint16_t *temp = dest;
    while (count--)
    {
        *temp++ = val;
    }
    return dest;
}

uint8_t *memcpy(uint8_t *dest, const uint8_t *src, size_t n)
{
    uint8_t *d = dest;
    const uint8_t *s = src;
    while (n--)
    {
        *d++ = *s++;
    }
    return dest;
}

int strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *strcpy(char *dst, const char *src)
{
    char c;
    char *p = dst;

    while ((c = *src++))
    {
        *p++ = c;
    }

    *p = '\0';
    return dst;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
        {
            return 0;
        }

        ++s1;
        ++s2;
    }

    return *s1 - *s2;
}

char *strcat(char *d, const char *s)
{
    strcpy(d + strlen(d), s);
    return d;
}

const char *strchr(const char *s, char ch)
{
    while (*s)
    {
        if (*s == ch)
            return s;
        s++;
    }
    return 0;
}

char *strtok(char *s, const char *delim)
{
    static char *oldword = 0;
    char *word;

    if (!s)
        s = oldword;

    while (*s && strchr(delim, *s))
        s++;

    if (!*s)
    {
        oldword = s;
        return 0;
    }

    word = s;
    while (*s && !strchr(delim, *s))
        s++;

    if (*s)
    {
        *s = 0;
        oldword = s + 1;
    }
    else
    {
        oldword = s;
    }

    return word;
}
