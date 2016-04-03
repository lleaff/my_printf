#include "my_printf.h"
#include <stdlib.h>
#include <stdarg.h>

#define BREAK_OR_SKIP_DOUBLE_PERCENT(format, j) \
  { \
    if (format[j + 1] == '%') \
      j += 2 ; \
    else \
      break ; \
  }

char *make_chunk(const char *format, int i, int j)
{
  char *str;

  if (i - j)
  {
    str = my_strnnew(format + i, j - i);
    ASSIGN_AND_FREE(str, replace_escapes_new(str));
    return (str);
  }
  else
    return (my_strnew(""));
}

void get_chunks_and_specifiers(const char* format,
    t_ll **chunks, t_ll **fspes)
{
  int i;
  int j;

  for (i = 0, j = 0; format[i] != '\0' && format[j] != '\0'; i = j + 1)
  {
    for (j = i; format[j] != '\0'; j++)
      if (format[j] == '%')
      {
        BREAK_OR_SKIP_DOUBLE_PERCENT(format, j);
      }
    *chunks = ll_append(*chunks, ll_new(make_chunk(format, i, j)));
    if (format[j] == '%')
      *fspes = ll_append(*fspes, ll_new(parse_specifier(format + j + 1, &j)));
  }
}

char *my_vsprintf(const char *format, va_list args)
{
  t_ll *chunks;
  t_ll *fspes;
  t_ll *formatted;
  t_ll *zipped;
  char *str;

  set_to(NULL, &chunks, &fspes, &formatted, NULL);
  get_chunks_and_specifiers(format, &chunks, &fspes);
  formatted = format_args(fspes, args);
  zipped = ll_zip(chunks, formatted);
  str = ll_concat_str(zipped);
  ll_free(zipped);
  ll_free(fspes);
  return (str);
}
