#ifndef MY_PRINTF_F_H
#define MY_PRINTF_F_H

#ifdef DEBUG
#include <stdio.h>
#endif

#include <stdarg.h>
#include "lib.h"

#define CHARSET_DECIMAL "0123456789"
#define CHARSET_HEXADECIMAL "0123456789abcdef"
#define CHARSET_HEXADECIMAL_UP "0123456789ABCDEF"

t_bool check_prog_args(int argc, char **argv);

char *pad_str_left(char *str, int w, char fill);
char *pad_str_right(char *str, int w, char fill);

char *replace_escapes_new(const char *str);

#define FLAGS "-+ #0"
extern const char g_SPECIFIERS[];

typedef enum {
  length_normal,
  length_short_short,
  length_short,
  length_long,
  length_long_long,
  length_long_double
} t_length_m;

extern const char g_LENGTH_MODIFIER_CHARS[];
t_length_m parse_length_modifier(const char *format, int *index);

#define HAS_FLAG(fspe, flag) (str_has((fspe)->flags, (flag)))

typedef struct s_fspe {
  char specifier;
  char flags[sizeof(FLAGS)];
  t_bool hasWidth;
  int width;
  t_bool hasPrecision;
  int precision;
  t_length_m length;
} t_fspe;

t_fspe *parse_specifier(const char *format, int *index);

typedef char *(*t_formatter)(void *, t_fspe *);

char *fmt_dec_int(void *, t_fspe *);
char *fmt_dec_uint(void *, t_fspe *);
char *fmt_oct_int(void *, t_fspe *);
char *fmt_hex_int(void *, t_fspe *);
char *fmt_hex_int_up(void *, t_fspe *);
char *fmt_char(void *, t_fspe *);
char *fmt_str(void *, t_fspe *);
char *fmt_ptr(void *, t_fspe *);
char *fmt_floating(void *, t_fspe *);
char *fmt_float_hex(void *, t_fspe *);
char *fmt_float_hex_up(void *, t_fspe *);

char *format_integer_base(void *np, t_fspe *fspe,
    int base, const char *charset);
char *format_integer_base_unsigned(void *np, t_fspe *fspe,
    int base, const char *charset);
char *format_floating_pt_base(void *np, t_fspe *fspe,
    int base, const char *charset);

char *call_with_int(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_uint(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_ldouble(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_char(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_pointer(t_formatter formatter, t_fspe *fspe, va_list args);

t_ll *format_args(t_ll *spcs, va_list args);

char *format_with(char *str, t_fspe *fspe);

char *my_vsprintf(const char *format, va_list arg);
char *my_sprintf(const char *format, ...);
int  my_printf(const char *format, ...);

#include "param_errors.h"

#ifdef DEBUG
void DEBUG_fspe(t_fspe *fspe);
#endif

#endif /* MY_PRINTF_F_H */
