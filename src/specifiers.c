#include "my_printf.h"

t_fspe *parse_specifier(const char *format, int *index)
{
  t_fspe *fspe;
  noop(format, index);

  if ((fspe = malloc(sizeof(*fspe))) == NULL)
    return (NULL);

  DEBUG_fspe(fspe); /* DEBUG */
  return (NULL);
}


#ifdef DEBUG
void DEBUG_fspe(t_fspe *fspe)
{
  my_putstr(FG_BLUE"t_fspe: { "FG_YELLOW);
  my_putchar(fspe->specifier);
  if (fspe->hasFlag)
  {
    my_putstr(FG_BLUE", flag: "FG_YELLOW);
    my_putchar(fspe->flag);
  }
  if (fspe->hasWidth)
  {
    my_putstr(FG_BLUE", width: "FG_YELLOW);
    my_put_nbr(fspe->width);
  }
  if (fspe->hasPrecision)
  {
    my_putstr(FG_BLUE", precision: "FG_YELLOW);
    my_put_nbr(fspe->precision);
  }
  my_putstr(FG_BLUE" }"COLOR_RESET"\n");
}
#endif
