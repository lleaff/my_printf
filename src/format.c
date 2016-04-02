#include <stdarg.h>
#include "my_printf.h"

const char g_SPECIFIERS[] = "diuoxXcsp";

const t_formatter g_FORMATTERS[sizeof(g_SPECIFIERS)] = {
  fmt_dec_int,
  fmt_dec_int,
  fmt_dec_uint,
  fmt_oct_int,
  fmt_hex_int,
  fmt_hex_int_up,
  fmt_char,
  fmt_str,
  fmt_ptr
};

t_formatter get_formatter(char c)
{
  int i;

  if ((i = char_in_str(c, g_SPECIFIERS)) < 0 || i > (int)sizeof(g_SPECIFIERS))
      return (NULL);
  return g_FORMATTERS[i];
}

char *call_formatter(t_fspe *fspe, va_list args)
{
  t_formatter formatter;
  char c;
  char *res;

  c = fspe->specifier;
  formatter = get_formatter(c);
  if (str_has("di", c))
    res = call_with_int(formatter, fspe, args);
  else if (str_has("uoxX", c))
    res = call_with_uint(formatter, fspe, args);
  else if ('c' == c)
    res = call_with_char(formatter, fspe, args);
  else if (str_has("sp", c))
    res = call_with_pointer(formatter, fspe, args);
  else
    res = NULL;
  return (res);
}

#define LL_FSPE(ll) ((t_fspe*)(ll)->data)

t_ll *format_args(t_ll *spcs, va_list args)
{
  t_ll *formatted;
  t_fspe *fspe;

  if (spcs == NULL)
    return (NULL);
  for (formatted = NULL; spcs != NULL; spcs = spcs->next)
  {
    fspe = LL_FSPE(spcs);
    formatted = ll_append(formatted, ll_new(call_formatter(fspe, args)));
  }
  return (formatted);
}
