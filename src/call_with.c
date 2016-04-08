#include <stdarg.h>
#include "my_printf_f.h"

char *call_with_int(t_formatter formatter, t_fspe *fspe, va_list args)
{
  t_llint n;
  t_length_m l;

  l = fspe->length;
  if (l <= length_normal)
      n = va_arg(args, int);
  else if (l <= length_long)
      n = va_arg(args, long int);
  else if (l <= length_long_long)
      n = va_arg(args, t_llint);
  else
      return (no_corresponding_length_error(fspe));
  return (formatter(&n, fspe));
}

char *call_with_uint(t_formatter formatter, t_fspe *fspe, va_list args)
{
  t_lluint n;
  t_length_m l;

  l = fspe->length;
  if (l <= length_normal)
      n = va_arg(args, unsigned int);
  else if (l <= length_long)
      n = va_arg(args, long unsigned int);
  else if (l <= length_long_long)
      n = va_arg(args, t_lluint);
  else
      return (no_corresponding_length_error(fspe));
  return (formatter(&n, fspe));
}

char *call_with_ldouble(t_formatter formatter, t_fspe *fspe, va_list args)
{
  long double n;
  t_length_m l;

  l = fspe->length;
  if (l == length_normal)
      n = va_arg(args, double);
  else if (l == length_long_double)
      n = va_arg(args, long double);
  else
      return (no_corresponding_length_error(fspe));
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
