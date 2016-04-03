#include <stdarg.h>
#include "my_printf_f.h"

char *call_with_int(t_formatter formatter, t_fspe *fspe, va_list args)
{
  t_llint n;

  switch (fspe->length)
  {
    case length_long:
      n = va_arg(args, long int);
      break ;
    case length_long_long:
      n = va_arg(args, t_llint);
      break ;
    case length_normal:
    case length_short:
    case length_short_short:
      n = va_arg(args, int);
      break ;
    default:
      return (no_corresponding_length_error(fspe));
  }
  return (formatter(&n, fspe));
}

char *call_with_uint(t_formatter formatter, t_fspe *fspe, va_list args)
{
  t_lluint n;

  switch (fspe->length)
  {
    case length_long:
      n = va_arg(args, long unsigned int);
      break ;
    case length_long_long:
      n = va_arg(args, t_lluint);
      break ;
    case length_normal:
    case length_short:
    case length_short_short:
      n = va_arg(args, unsigned int);
      break ;
    default:
      return (no_corresponding_length_error(fspe));
  }
  return (formatter(&n, fspe));
}

char *call_with_ldouble(t_formatter formatter, t_fspe *fspe, va_list args)
{
  long double n;

  switch (fspe->length)
  {
    case length_long_double:
      n = va_arg(args, long double);
      break ;
    case length_normal:
      n = va_arg(args, double);
      break ;
    default:
      return (no_corresponding_length_error(fspe));
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
