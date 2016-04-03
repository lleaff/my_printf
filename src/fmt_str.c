#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_str(void *s, t_fspe *fspe)
{
  char *str;

  str = format_with(my_strnew(s), fspe);
  return (str);
}
