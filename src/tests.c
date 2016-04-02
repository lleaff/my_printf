#include "my_printf.h"

#define TEST1_FRM "Hello%%.\n"
#define TEST1_RES (STRLEN(TEST1_FRM) - 1)

#define TEST2_FRM "Hello %s.\n"
#define TEST2_ARG1 "world"
#define TEST2_RES (STRLEN(TEST2_FRM) + STRLEN(TEST2_ARG1) - 2)

#define TEST3_FRM "123? [%-6.4d].\n"
#define TEST3_ARG1 123
#define TEST3_RES (STRLEN(TEST3_FRM) + 3)

#define TEST4_FRM "255 (FF)? [%#X].\n"
#define TEST4_ARG1 255
#define TEST4_RES (STRLEN(TEST4_FRM) + 1)

int g_failures;

static void assert(char *msg, t_bool res)
{
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
  printf("%04d\n", 14);
  g_failures = 0;
  assert("1", my_printf(TEST1_FRM) == TEST1_RES);
  assert("2", my_printf(TEST2_FRM, TEST2_ARG1) == TEST2_RES);
  assert("3", my_printf(TEST3_FRM, TEST3_ARG1) == TEST3_RES);
  assert("4", my_printf(TEST4_FRM, TEST4_ARG1) == TEST4_RES);
  return (g_failures);
}

