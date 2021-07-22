#ifndef __HANSI_PARSER_H__
#define __HANSI_PARSER_H__

#define MAX_ARGS 8
#define HTERM_ESC 1
#define HTERM_BRACKET 2
#define HTERM_ARGS 3
#define HTERM_ENDARGS 4

#include <stdbool.h>

typedef struct
{
    int value;
    bool empty;
} ansi_args;

typedef struct
{
    int state;
    int index;
    ansi_args args[MAX_ARGS];
} hansi_parser;

void hansi_handler(char c);

#endif
