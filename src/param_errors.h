#ifndef PARAM_ERRORS_H
#define PARAM_ERRORS_H

#include "my_printf_f.h"

void *unknown_conversion_type_specifier_error(t_fspe *fspe, char c);
void *no_corresponding_length_error(t_fspe *fspe);
void *no_corresponding_formatter_error(t_fspe *fspe);

#endif /* PARAM_ERRORS_H */
