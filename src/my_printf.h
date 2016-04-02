#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#define DEBUG
#ifdef DEBUG
#include <stdio.h>
#endif

#include "lib.h"

t_bool check_prog_args(int argc, char **argv);

typedef struct s_fspe {
  char specifier;
  t_bool hasFlag;
  char flag;
  t_bool hasWidth;
  int width;
  t_bool hasPrecision;
  int precision;
} t_fspe;

t_fspe *parse_specifier(const char *format, int *index);

char *my_vsprintf(const char *format, va_list arg);
char *my_sprintf(const char *format, ...);
int  my_printf(const char *format, ...);

#endif /* MY_PRINTF_H */
