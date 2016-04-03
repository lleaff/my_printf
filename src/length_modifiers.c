#include "my_printf_f.h"

const char g_LENGTH_MODIFIER_CHARS[] = "hl";

t_length_m parse_length_modifier(const char *format, int *index)
{
  int i;
  t_length_m mod;

  i = 0;
  mod = length_normal;
  if (format[i] == 'h')
  {
      if (format[++i] == 'h')
        mod = ++i ? length_short_short : length_normal;
      else
        mod = length_short;
  }
  else if (format[i] == 'l')
  {
      if (format[++i] == 'l')
        mod = ++i ? length_long_long : length_normal;
      else
        mod = length_long;
  }
  index += i;
  return (mod);
}
