#include "my_printf.h"
#include "lib.h"

#define TEST1_FRM "Hello%%."
#define TEST1_RES (STRLEN(TEST1_FRM) - 1)

#define TEST2_FRM "%s world%c."
#define TEST2_ARG1 "Hello"
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

#define TEST6_FRM "+4.123000 (4.123)? [%f]"
#define TEST6_ARG1 4.123
#define TEST6_RES (STRLEN(TEST6_FRM) + 6)

#define TEST7_FRM "-4.123457 (-4.123456789)? [%.5f]."
#define TEST7_ARG1 -4.123456789
#define TEST7_RES (STRLEN(TEST7_FRM) + 4)

#define TEST8_FRM "+ (456.123)? [%a]."
#define TEST8_ARG1 456.123
#define TEST8_RES (STRLEN(TEST8_FRM) + 10)

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
  assert("6", my_printf(TEST6_FRM, TEST6_ARG1) == TEST6_RES);
  assert("7", my_printf(TEST7_FRM, TEST7_ARG1) == TEST7_RES);
  assert("8", my_printf(TEST8_FRM, TEST8_ARG1) == TEST8_RES);
  return (g_failures);
}
