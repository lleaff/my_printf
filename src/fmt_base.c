#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_oct_int(void *np, t_fspe *fspe)
{
  char *str;

  str = format_with_base_unsigned(np, fspe, 8, "01234567");
  ASSIGN_AND_FREE(str, my_strcatnew("0", str));
  return (str);
}

char *fmt_hex_int(void *np, t_fspe *fspe)
{
  char *str;

  str = format_with_base(np, fspe, 16, "0123456789abcdef");
  ASSIGN_AND_FREE(str, my_strcatnew("0x", str));
  return (str);
}

char *fmt_hex_int_up(void *np, t_fspe *fspe)
{
  char *str;

  str = format_with_base(np, fspe, 16, "0123456789ABCDEF");
  ASSIGN_AND_FREE(str, my_strcatnew("0X", str));
  return (str);
}
