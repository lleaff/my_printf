A minimal printf implementation with no float support and no buffering.

```c
int  my_printf(const char *format, ...);
char *my_sprintf(const char *format, ...);

char *my_vsprintf(const char *format, va_list arg);
```

###Format specifier format:

    %[flags][width][.precision][length]specifier

####Specifiers:

| Specifier  | Output format                            |
|------------|------------------------------------------|
| `d` or `i` | Integer                                  |
| `u`        | Unsigned integer                         |
| `o`        | Unsigned octal integer                   |
| `x`        | Unsigned hexadecimal integer             |
| `X`        | Unsigned hexadecimal integer (uppercase) |
| `c`        | Character                                |
| `s`        | String                                   |
| `p`        | Pointer address                          |

####Flags:

| Flag       | Effect                                               |
|------------|------------------------------------------------------|
| `-`        | Justify to the left instead of right.                |
| `+`        | Force sign display.                                  |
| ` `        | Prepend a space if no sign is present.               |
| `#`        | Prepend base prefix (`o => 0`, `x => 0x`, `X => 0X`) |
| `0`        | Pad number with `0` instead of spaces.               |

####Length:

| Length | Type            |
|--------|-----------------|
| `hh`   | `char`          |
| `h`    | `short ...`     |
| `l`    | `long ...`      |
| `ll`   | `long long ...` |
