#include "my_printf.h"

char *pad_str_left(char *str, int w, char fill)
{
  int len;
  char *s;
  int i;

  len = my_strlen(str);
  if (len >= w)
    return (my_strnew(str));
  MALLOC_MB(s, w);
  for (i = 0; *str; i++, str++)
    s[i] = *str;
  for (; i < w; i++)
    s[i] = fill;
  s[i + 1] = '\0';
  return (s);
}

char *pad_str_right(char *str, int w, char fill)
{
  int len;
  char *s;
  int i;

  len = my_strlen(str);
  if (len >= w)
    return (my_strnew(str));
  MALLOC_MB(s, w);
  for (i = 0; i < w - len; i ++)
    s[i] = fill;
  for (; *str; )
    s[i++] = *str++;
  s[i + 1] = '\0';
  return (s);
}
