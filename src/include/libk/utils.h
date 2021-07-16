#ifndef __UTILS_H__
#define __UTILS_H__

#include <init/stivale2.h>

void fetch();

void init_arg_parser(struct stivale2_struct *bootinfo);
int arg_exist(char *arg);
void print_args();

#endif
