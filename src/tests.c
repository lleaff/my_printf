#include "my_printf_f.h"

#define TEST1_FRM "Hello%%."
#define TEST1_RES (STRLEN(TEST1_FRM) - 1)

#define TEST2_FRM "Hello %s%c."
#define TEST2_ARG1 "world"
#define TEST2_ARG2 '!'
#define TEST2_RES (STRLEN(TEST2_FRM) + STRLEN(TEST2_ARG1) - 3)

#define TEST3_FRM "123? [%-6.4d]."
#define TEST3_ARG1 123
#define TEST3_RES (STRLEN(TEST3_FRM))

#define TEST4_FRM "255 (FF)? [%#X]."
#define TEST4_ARG1 255
#define TEST4_RES (STRLEN(TEST4_FRM) + 1)

#define TEST5_FRM "+33 (33)? [%+i] && -22 (-22)? [%-d]."
#define TEST5_ARG1 33
#define TEST5_ARG2 -22
#define TEST5_RES (STRLEN(TEST5_FRM))

int g_failures;

static void assert(char *msg, t_bool res)
{
  my_putchar('\n');
  if (res)
  {
    my_putstr(FG_WHITE""BG_GREEN"[SUCCESS] ");
    my_putstr(msg);
    my_putstr(" "COLOR_RESET"\n");
  }
  else
  {
    my_putstr(FG_WHITE""BG_RED"[FAILED] ");
    my_putstr(msg);
    my_putstr(" "COLOR_RESET"\n");
    g_failures++;
  }
}

int tests()
{
  g_failures = 0;
  assert("1", my_printf(TEST1_FRM) == TEST1_RES);
  assert("2", my_printf(TEST2_FRM, TEST2_ARG1, TEST2_ARG2) == TEST2_RES);
  assert("3", my_printf(TEST3_FRM, TEST3_ARG1) == TEST3_RES);
  assert("4", my_printf(TEST4_FRM, TEST4_ARG1) == TEST4_RES);
  assert("5", my_printf(TEST5_FRM, TEST5_ARG1, TEST5_ARG2) == TEST5_RES);
  return (g_failures);
}

