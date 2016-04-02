#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#define DEBUG
#ifdef DEBUG
#include <stdio.h>
#endif

#include "lib.h"

t_bool check_prog_args(int argc, char **argv);

#define FLAGS "-+ #0"
extern const char g_SPECIFIERS[];

typedef enum {
  length_normal,
  length_short_short,
  length_short,
  length_long,
  length_long_long
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

char *call_with_int(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_uint(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_char(t_formatter formatter, t_fspe *fspe, va_list args);
char *call_with_pointer(t_formatter formatter, t_fspe *fspe, va_list args);

t_ll *format_args(t_ll *spcs, va_list args);

char *format_with(char *str, t_fspe *fspe);

char *my_vsprintf(const char *format, va_list arg);
char *my_sprintf(const char *format, ...);
int  my_printf(const char *format, ...);

#ifdef DEBUG
void DEBUG_fspe(t_fspe *fspe);
#endif

#endif /* MY_PRINTF_H */
