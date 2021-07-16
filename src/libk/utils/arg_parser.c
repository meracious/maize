#include <init/stivale2.h>
#include <libk/stdio.h>
#include <libk/string.h>
#include <libk/utils.h>

char *kernel_arguments[128];
int kernel_argc = 0;

void init_arg_parser(struct stivale2_struct *bootinfo)
{
    struct stivale2_struct_tag_cmdline *cmdline = (struct stivale2_struct_tag_cmdline *)stivale2_get_tag(bootinfo, STIVALE2_STRUCT_TAG_CMDLINE_ID);

    char *args = (char *)cmdline->cmdline;

    kernel_arguments[kernel_argc] = strtok(args, " ");
    while (kernel_arguments[kernel_argc])
    {
        kernel_argc++;
        kernel_arguments[kernel_argc] = strtok(0, " ");
    }
}

int arg_exist(char *arg)
{
    for (int i = 0; i < kernel_argc; i++)
    {
        if (!strcmp(arg, kernel_arguments[i]))
            return 1;
    }
    return 0;
}

void print_args()
{
    puts("Kernel Arguments: ");
    for (int i = 0; i < kernel_argc; i++)
    {
        printf("%s ", kernel_arguments[i]);
    }
}
