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
  return (replace_escapes_new(my_strnnew(format + i, j - i)));
}

void get_chunks_and_specifiers(const char* format,
    t_ll **chunks, t_ll **fspes)
{
  char c;
  int i;
  int j;

  for (i = 0, c = format[i]; c != '\0'; i = j + 1)
  {
    for (j = i, c = format[j]; c != '\0'; j++, c = format[j])
      if (c == '%')
        BREAK_OR_SKIP_DOUBLE_PERCENT(format, j);
    *chunks = ll_append(*chunks, ll_new(make_chunk(format, i, j)));
    if (c == '%')
      *fspes = ll_append(*fspes, ll_new(parse_specifier(format + j + 1, &j)));
    /* printf("i(%d) j(%d)\n", i, j); *//* DEBUG */
  }
}

char *my_vsprintf(const char *format, va_list args)
{
  t_ll *chunks;
  t_ll *fspes;
  t_ll *formatted;

  set_to(NULL, &chunks, &fspes, &formatted, NULL);
  get_chunks_and_specifiers(format, &chunks, &fspes);
  formatted = format_args(fspes, args);
  my_putstr("Chunks: "); ll_debug_strings(chunks); /* DEBUG */
  my_putstr("Formatted: "); ll_debug_strings(formatted); /* DEBUG */
  return (ll_concat_str(ll_zip(chunks, formatted)));
}
