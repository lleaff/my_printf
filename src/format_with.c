#include "my_printf.h"

char *format_with(char *str, t_fspe *fspe)
{
  char *s;
  char fill;

  fill = HAS_FLAG(fspe, '0') ? '0' : ' ';
  if (fspe->hasWidth)
  {
    s = (HAS_FLAG(fspe, '-') ? pad_str_left : pad_str_right)(str,
        fspe->width, fill);
    free(str);
  }
  else
    s = str;
  return (s);
}
