#include "my_printf.h"

char *format_with_base(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  long long int n;
  char *str;

  n = *(long long int*)np;
  RETURN_IF_NULL(str = my_longlongtoa_base(n, base, charset));
  str = format_with(str, fspe);
  return (str);
}

char *format_with_base_unsigned(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  long long unsigned int n;
  char *str;

  n = *(long long unsigned int*)np;
  RETURN_IF_NULL(str = my_longlongunsignedtoa_base(n, base, charset));
  str = format_with(str, fspe);
  return (str);
}
