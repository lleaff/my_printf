#include "my_printf.h"
#include <stdlib.h>
#include <stdarg.h>

char *my_sprintf(const char *format, ...)
{
  char *str;
  va_list args;

  va_start(args, format);
  str = my_vsprintf(format, args);
  va_end(args);
  return (str);
}

int my_printf(const char *format, ...)
{
  char *str;
  va_list args;

  va_start(args, format);
  str = my_vsprintf(format, args);
  va_end(args);
  my_putstr(str);
  return (my_strlen(str));
}
