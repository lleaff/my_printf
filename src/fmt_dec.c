#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_dec_int(void *np, t_fspe *fspe)
{
  char *str;

  str = format_integer_base(np, fspe, 10, "0123456789");
  str = format_with(str, fspe);
  return (str);
}

char *fmt_dec_uint(void *np, t_fspe *fspe)
{
  char *str;

  str = format_integer_base_unsigned(np, fspe, 10, "0123456789");
  str = format_with(str, fspe);
  return (str);
}
