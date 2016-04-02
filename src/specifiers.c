#include "my_printf.h"

#define SET_WIDTH(fspe, w) \
  (fspe)->hasWidth = true; \
  (fspe)->width = w;

#define SET_PRECISION(fspe, p) \
  (fspe)->hasPrecision = true; \
  (fspe)->precision = p;

void *unkown_conversion_type_specifier_error(t_fspe *fspe, char c)
{
  free(fspe);
  my_puterr(FG_RED"ERROR: Unknown conversion type character ‘");
  my_putcharerr(c);
  my_puterr("‘ in format.\n"COLOR_RESET);
  return (NULL);
}

t_bool fspe_set_flag(t_fspe *fspe, char flag)
{
  if (HAS_FLAG(fspe, flag))
    return (false);
  append_char(fspe->flags, flag);
  return (true);
}

int parse_format_uint(const char *format, int *index)
{
  noop(format, index);
  int num;
  int i;

  for (i = 0, num = 0; IS_DIGIT(format[i]); i++)
    num = num * 10 + CHAR_TO_INT(format[i]);
  *index += i;
  return (i == 0 ? -1 : num);
}

t_fspe *parse_specifier(const char *format, int *index)
{
  t_fspe *fspe;
  int i;
  int num;

  if ((fspe = my_calloc(sizeof(*fspe))) == NULL)
    return (NULL);
  for (i = 0; str_has(FLAGS, format[i]); i++)
    fspe_set_flag(fspe, format[i]);
  if ((num = parse_format_uint(format + i, &i)) != -1)
    SET_WIDTH(fspe, num);
  if (format[i] == '.')
    if ((num = parse_format_uint(format + ++i, &i)) != -1)
      SET_PRECISION(fspe, num);
  if (str_has(g_LENGTH_MODIFIER_CHARS, format[i]))
    fspe->length = parse_length_modifier(format + i, &i);
  if (str_has(g_SPECIFIERS, format[i]))
    fspe->specifier = format[i++];
  else
    return unkown_conversion_type_specifier_error(fspe, format[i]);
  *index += i;
  DEBUG_fspe(fspe); /* DEBUG */
  return (fspe);
}

#ifdef DEBUG
void DEBUG_fspe(t_fspe *fspe)
{
  my_putstr(FG_BLUE"t_fspe: { "FG_YELLOW);
  my_putchar(fspe->specifier);
  if (*(fspe->flags))
  {
    my_putstr(FG_BLUE", flags: "FG_YELLOW);
    my_putstr(fspe->flags);
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
