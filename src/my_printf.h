#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include "lib.h"

#define DEBUG
#ifdef DEBUG
#include <stdio.h>
#endif

t_bool check_prog_args(int argc, char **argv);

int my_printf (const char *format, ...);

#endif /* MY_PRINTF_H */
