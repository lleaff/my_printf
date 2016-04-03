#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_ptr(void *np, t_fspe *fspe)
{
  char *str;

  str = fmt_hex_int(np, fspe);
  ASSIGN_AND_FREE(str, my_strcatnew("0X", str));
  return (str);
}
