#include <stdlib.h>
#include "my_printf.h"

char *fmt_dec_int(void *np, t_fspe *fspe)
{
  long long int n;
  char *str;

  n = *(long long int*)np;
  RETURN_IF_NULL(str = my_longlongtoa(n));
  str = format_with(str, fspe);
  return (str);
}

char *fmt_dec_uint(void *np, t_fspe *fspe)
{
  long long unsigned int n;
  char *str;

  n = *(long long unsigned int*)np;
  RETURN_IF_NULL(str = my_longlongunsignedtoa(n));
  str = format_with(str, fspe);
  return (str);
}
