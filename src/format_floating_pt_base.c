#include "my_printf_f.h"

#define DEFAULT_PRECISION_FP 6

t_lluint get_fractional_part_base(long double n, int precision, int base)
{
  t_lluint fp;
  int sign;

  sign = n >= 0 ? 1 : -1;
  for (fp = 0; precision; precision--)
  {
    fp = fp * base + (((t_llint)(n * base) % base) * sign);
    n *= base;
  }
  fp += (((t_llint)(n * base) % base) * sign) >= 5 ? 1 : 0;
  return (fp);
}

char *format_fractional_part_base(long double n, int precision, int base,
    const char *charset)
{
  char *str;
  t_lluint fract_p;

  fract_p = get_fractional_part_base(n, precision, base);
  str = my_longlongtoa_base(fract_p, base, charset);
  ASSIGN_AND_FREE(str, my_strcatnew(".", str));
  return (str);
}

char *format_floating_pt_base(void *np, t_fspe *fspe,
    int base, const char *charset)
{
  int precision;
  char *str;
  long double n;
  char *fract;

  n = *(long double*)np;
  precision= fspe->hasPrecision ? fspe->precision : DEFAULT_PRECISION_FP;
  printf("n = (%Lf)\n", n);/* DEBUG */
  printf("my_longlongtoa_base(%lld)\n", (t_llint)n);/* DEBUG */
  RETURN_IF_NULL(str = my_longlongtoa_base((t_llint)n, base, charset));
  fract = format_fractional_part_base(n, precision, base, charset);
  printf("fract_p: (%s)\n", fract); /* DEBUG */
  ASSIGN_AND_FREE(str, my_strcatnew(str, fract));
  free(fract);
  str = format_with(str, fspe);
  return (str);
}
