#include "my_printf_f.h"
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
  int len;

  va_start(args, format);
  str = my_vsprintf(format, args);
  va_end(args);
  my_putstr(str);
  len = my_strlen(str);
  free(str);
  return (len);
}
