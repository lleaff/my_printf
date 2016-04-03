#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_char(void *cp, t_fspe *fspe)
{
  char c;
  char *str;

  c = *(char*)cp;
  MALLOC_MB(str, 2);
  str[0] = c;
  str[1] = '\0';
  str = format_with(str, fspe);
  return (str);
}
