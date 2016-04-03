#include <stdlib.h>
#include "my_printf_f.h"

char *fmt_floating(void *np, t_fspe *fspe)
{
  char *str;

  str = format_floating_pt_base(np, fspe, 10, "0123456789");
  return (str);
}
