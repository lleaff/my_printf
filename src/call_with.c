#include <stdarg.h>
#include "my_printf_f.h"

char *call_with_int(t_formatter formatter, t_fspe *fspe, va_list args)
{
  long long int n;

  switch (fspe->length)
  {
    case length_long:
      n = va_arg(args, long int);
      break ;
    case length_long_long:
      n = va_arg(args, long long int);
      break ;
    case length_normal:
    case length_short:
    case length_short_short:
    default:
      n = va_arg(args, int);
      break ;
  }
  return (formatter(&n, fspe));
}

char *call_with_uint(t_formatter formatter, t_fspe *fspe, va_list args)
{
  unsigned long long int n;

  switch (fspe->length)
  {
    case length_long:
      n = va_arg(args, unsigned long int);
      break ;
    case length_long_long:
      n = va_arg(args, unsigned long long int);
      break ;
    case length_normal:
    case length_short:
    case length_short_short:
    default:
      n = va_arg(args, unsigned int);
      break ;
  }
  return (formatter(&n, fspe));
}

char *call_with_char(t_formatter formatter, t_fspe *fspe, va_list args)
{
  char c;

  c = (char)va_arg(args, int);
  return (formatter(&c, fspe));
}

char *call_with_pointer(t_formatter formatter, t_fspe *fspe, va_list args)
{
  void *str;

  str = va_arg(args, void*);
  return (formatter(str, fspe));
}
