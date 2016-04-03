#include "my_printf.h"

char *apply_precision(char *str, t_fspe *fspe)
{
  int precision;

  if (!fspe->hasPrecision)
    return (str);
  precision = fspe->precision;
  if (!my_strcmp(str, "0"))
    return (ASSIGN_AND_FREE(str, my_strnew("")));
  ASSIGN_AND_FREE(str, pad_str_right(str, precision, '0'));
  return (str);
}

char *apply_forced_sign(char *str, t_fspe *fspe)
{
  if (!HAS_FLAG(fspe, '+') || *str == '-')
    return (str);
  ASSIGN_AND_FREE(str, my_strcatnew("+", str));
  return (str);
}

char *format_with_base(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  long long int n;
  char *str;

  n = *(long long int*)np;
  RETURN_IF_NULL(str = my_longlongtoa_base(n, base, charset));
  str = apply_forced_sign(str, fspe);
  str = apply_precision(str, fspe);
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
  str = apply_precision(str, fspe);
  str = format_with(str, fspe);
  return (str);
}
