SRCFILES = \
			call_with.c \
			escapes.c \
			fmt_base.c \
			fmt_char.c \
			fmt_dec.c \
			fmt_floating.c \
			fmt_ptr.c \
			fmt_str.c \
			format.c \
			format_floating_pt_base.c \
			format_integer_base.c \
			format_with.c \
			length_modifiers.c \
			main.c \
			my_printf.c \
			pad_str.c \
			param_errors.c \
			prog_args.c \
			specifiers.c \
			tests.c \
			vsprintf.c

OUT =	my_printf

CFLAGS = -g -Werror -Wall -Wextra
CC = gcc

SRC = $(patsubst %,src/%,$(SRCFILES))
OBJ = $(SRC:.c=.o)

LIB = libmy.a
LIB_DIR = lib

INCLUDES = -Ilib

all: $(OUT)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUT): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(LIB)

$(LIB): $(LIB_DIR)
	make -C $(LIB_DIR)

re: fclean all
	make -C $(LIB_DIR) re

clean:
	rm -f $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(OUT)
	make -C $(LIB_DIR) fclean
