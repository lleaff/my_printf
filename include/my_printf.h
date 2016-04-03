#ifndef MY_PRINTF_H
#define MY_PRINTF_H

char *my_sprintf(const char *format, ...);
int  my_printf(const char *format, ...);

#include <stdarg.h>

char *my_vsprintf(const char *format, va_list arg);

#endif /* MY_PRINTF_H */
