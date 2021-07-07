#ifndef __STRING_H__
#define __STRING_H__

#include <stddef.h>
#include <stdint.h>

char *itoa(int value, char *str, int base);
char *utoa(uint64_t value, char *str, uint8_t base);

void *memset(void *bufptr, int value, size_t size);
uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count);
uint8_t *memcpy(uint8_t *dest, const uint8_t *src, size_t n);

int strlen(const char *str);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
char *strcat(char *d, const char *s);
const char *strchr(const char *s, char ch);
char *strtok(char *s, const char *delim);

#endif
