#include "my_printf_f.h"

t_bool check_prog_args(int argc, char **argv)
{
  noop(argv);
  if (argc < 2)
  {
    return (false);
  }
  else
  {
    return (true);
  }
}
