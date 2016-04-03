#include "my_printf_f.h"

#define DEFAULT_PRECISION_FP 6

t_lluint get_fractional_part_base(long double n, int precision, int base)
{
  t_lluint fp;
  for (fp = 0; precision; precision--)
  {
    fp = fp * base + ((t_lluint)(n * base) % base);
    n *= base;
  }
  return (fp);
}

char *format_floating_pt_base(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  int precision;
  char *str;
  long double n;
  t_lluint fract_p;

  n = *(long double*)np;
  precision= fspe->hasPrecision ? fspe->precision : DEFAULT_PRECISION_FP;
  RETURN_IF_NULL(str = my_longlongtoa_base((long long)n, base, charset));
  fract_p = get_fractional_part_base((long long)n, precision, base);
  printf("fract_p: (%llu)\n", fract_p); /* DEBUG */
  ASSIGN_AND_FREE(str, my_strcatnew(str,
        my_longlongtoa_base(fract_p, base, charset)));
  str = format_with(str, fspe);
  return (str);
}
