#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_floating(void *np, t_fspe *fspe)
{
  char *str;

  str = format_floating_pt_base(np, fspe, 10, CHARSET_DECIMAL);
  return (str);
}

char *fmt_float_hex(void *np, t_fspe *fspe)
{
  char *str;

  str = format_floating_pt_base(np, fspe, 16, CHARSET_HEXADECIMAL);
  ASSIGN_AND_FREE(str, my_strcatnew("0x", str));
  return (str);
}

char *fmt_float_hex_up(void *np, t_fspe *fspe)
{
  char *str;

  str = format_floating_pt_base(np, fspe, 16, CHARSET_HEXADECIMAL_UP);
  ASSIGN_AND_FREE(str, my_strcatnew("0X", str));
  return (str);
}
