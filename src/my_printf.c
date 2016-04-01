#include "my_printf.h"
#include <stdarg.h>

int my_printf (const char *format, ...)
{
  return (my_strlen((char*)format));
}
