#include "my_printf_f.h"

void *unknown_conversion_type_specifier_error(t_fspe *fspe, char c)
{
  my_puterr(FG_RED"ERROR: Unknown conversion type character ‘");
  my_putcharerr(c);
  my_puterr("‘ in format.\n"COLOR_RESET);
  free(fspe);
  return (NULL);
}

void *no_corresponding_length_error(t_fspe *fspe)
{
  my_puterr(FG_RED"ERROR: No caller found for ‘");
  my_putcharerr(fspe->specifier);
  my_puterr("‘ specifier and given length modifier.\n"COLOR_RESET);
  return (NULL);
}

void *no_corresponding_formatter_error(t_fspe *fspe)
{
  my_puterr(FG_RED"ERROR: No corresponding formatter found for ‘");
  my_putcharerr(fspe->specifier);
  my_puterr("‘ specifier.\n"COLOR_RESET);
  return (NULL);
}
