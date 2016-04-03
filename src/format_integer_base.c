#include "my_printf_f.h"

char *apply_precision_integer(char *str, t_fspe *fspe)
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

char *apply_sign_flags(char *str, t_fspe *fspe)
{
  if (*str == '-')
    return (str);
  if (HAS_FLAG(fspe, '+'))
    ASSIGN_AND_FREE(str, my_strcatnew("+", str));
  else if (HAS_FLAG(fspe, ' '))
    ASSIGN_AND_FREE(str, my_strcatnew(" ", str));
  return (str);
}

char *format_integer_base(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  t_llint n;
  char *str;

  n = *(t_llint*)np;
  RETURN_IF_NULL(str = my_longlongtoa_base(n, base, charset));
  str = apply_sign_flags(str, fspe);
  str = apply_precision_integer(str, fspe);
  str = format_with(str, fspe);
  return (str);
}

char *format_integer_base_unsigned(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  t_lluint n;
  char *str;

  n = *(t_lluint*)np;
  RETURN_IF_NULL(str = my_longlongunsignedtoa_base(n, base, charset));
  str = apply_precision_integer(str, fspe);
  str = format_with(str, fspe);
  return (str);
}
