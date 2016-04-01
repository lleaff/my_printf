#include "my_printf.h"

int main(int argc, char **argv)
{
  noop2(&argc, argv); /* DEBUG */
  if (!check_prog_args(argc, argv))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
