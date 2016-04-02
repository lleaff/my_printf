#include "my_printf.h"

char *call_with_int(t_formatter formatter, t_fspe *fspe, va_list args)
{
  noop(formatter, fspe, args);
  return ("");
}

char *call_with_uint(t_formatter formatter, t_fspe *fspe, va_list args)
{
  noop(formatter, fspe, args);
  return ("");
}

char *call_with_char(t_formatter formatter, t_fspe *fspe, va_list args)
{
  noop(formatter, fspe, args);
  return ("");
}

char *call_with_string(t_formatter formatter, t_fspe *fspe, va_list args)
{
  noop(formatter, fspe, args);
  return ("");
}

char *call_with_pointer(t_formatter formatter, t_fspe *fspe, va_list args)
{
  noop(formatter, fspe, args);
  return ("");
}
