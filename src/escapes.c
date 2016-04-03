#include "my_printf_f.h"

const char* g_ESCAPES[] = {
  "%%"
};

const char* g_REPLACEMENTS[] = {
  "%"
};

static int get_escape_index(const char *str)
{
  int i;
  const char *escape;
  int escape_c;

  escape_c = (int)(sizeof(g_ESCAPES) / sizeof(*g_ESCAPES));
  for (i = 0; i < escape_c; i++)
  {
    escape = g_ESCAPES[i];
    if (!my_strncmp(str + i, escape, my_strlen(escape) - 1))
      return (i);
  }
  return (-1);
}

char *replace_escapes_new(const char *str)
{
  int len;
  char *nstr;
  int i;
  int j;
  int escapei;

  len = my_strlen(str);
  MALLOC_MB(nstr, len + 1);
  for (i = 0, j = 0; i < len; i++, j++)
  {
    if ((escapei = get_escape_index(str + i)) != -1)
    {
      j += my_strcat(nstr, g_REPLACEMENTS[escapei]) - 1;
      i += my_strlen(g_ESCAPES[escapei]) - 1;
    }
    else
    nstr[j] = str[i];
  }
  nstr[j] = '\0';
  return (realloc(nstr, j));
}
