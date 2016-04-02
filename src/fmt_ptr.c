#include <stdlib.h>
#include "my_printf.h"

/* TODO prepend with 0x */
char *fmt_ptr(void *np, t_fspe *fspe)
{
  char *str;

  str = fmt_hex_int(np, fspe);
  return (str);
}
