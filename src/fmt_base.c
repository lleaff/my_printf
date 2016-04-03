#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_oct_int(void *np, t_fspe *fspe)
{
  char *str;

  str = format_integer_base_unsigned(np, fspe, 8, "01234567");
  if (HAS_FLAG(fspe, '#'))
    ASSIGN_AND_FREE(str, my_strcatnew("0", str));
  return (str);
}

char *fmt_hex_int(void *np, t_fspe *fspe)
{
  char *str;

  str = format_integer_base(np, fspe, 16, "0123456789abcdef");
  if (HAS_FLAG(fspe, '#'))
    ASSIGN_AND_FREE(str, my_strcatnew("0x", str));
  return (str);
}

char *fmt_hex_int_up(void *np, t_fspe *fspe)
{
  char *str;

  str = format_integer_base(np, fspe, 16, "0123456789ABCDEF");
  if (HAS_FLAG(fspe, '#'))
    ASSIGN_AND_FREE(str, my_strcatnew("0X", str));
  return (str);
}
