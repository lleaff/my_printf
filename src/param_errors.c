#include "my_printf.h"

void *unkown_conversion_type_specifier_error(t_fspe *fspe, char c)
{
  free(fspe);
  my_puterr(FG_RED"ERROR: Unknown conversion type character ‘");
  my_putcharerr(c);
  my_puterr("‘ in format.\n"COLOR_RESET);
  return (NULL);
}

