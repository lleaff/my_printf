#include <stdlib.h>
#include "my_printf.h"

static char *_fmt_with_base(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  long long int n;
  char *str;

  n = *(long long int*)np;
  RETURN_IF_NULL(str = my_longlongtoa_base(n, base, charset));
  str = format_with(str, fspe);
  return (str);
}

static char *_fmt_with_base_unsigned(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  long long unsigned int n;
  char *str;

  n = *(long long unsigned int*)np;
  RETURN_IF_NULL(str = my_longlongunsignedtoa_base(n, base, charset));
  str = format_with(str, fspe);
  return (str);
}

char *fmt_oct_int(void *np, t_fspe *fspe)
{
  char *str;

  str = _fmt_with_base_unsigned(np, fspe, 8, "01234567");
  return (str);
}

char *fmt_hex_int(void *np, t_fspe *fspe)
{
  char *str;

  str = _fmt_with_base(np, fspe, 16, "0123456789abcdef");
  return (str);
}

char *fmt_hex_int_up(void *np, t_fspe *fspe)
{
  char *str;

  str = _fmt_with_base(np, fspe, 16, "0123456789ABCDEF");
  return (str);
}
