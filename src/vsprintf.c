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
    *chunks = ll_append(*chunks, ll_new(my_strnnew(format + i, j - i)));
    if (c == '%')
      *fspes = ll_append(*fspes, ll_new(parse_specifier(format + i, &j)));
    printf("i(%d) j(%d)\n", i, j);/* DEBUG */
  }
}

char *my_vsprintf(const char *format, va_list arg)
{
  noop(format, arg); /* DEBUG */
  t_ll *chunks;
  t_ll *fspes;
  t_ll *formatted;

  set_to(NULL, &chunks, &fspes, &formatted, NULL);
  get_chunks_and_specifiers(format, &chunks, &fspes);
  ll_debug_strings(chunks);
  return (""); /*DEBUG*/
}
