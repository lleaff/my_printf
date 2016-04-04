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
			my_printf.c \
			pad_str.c \
			param_errors.c \
			prog_args.c \
			specifiers.c \
			vsprintf.c

OUT =	my_printf

CFLAGS = -Werror -Wall -Wextra
CC = gcc
AR = ar

SRC = $(patsubst %,src/%,$(SRCFILES))
SOBJ_DIR =  .static_obj
SOBJ :=  $(SRC:src/%.c=$(SOBJ_DIR)/%.o)
DOBJ_DIR =  .shared_obj
DOBJ :=  $(SRC:src/%.c=$(DOBJ_DIR)/%.o)

LIB = libmy.a
LIB_DIR = lib

INCLUDES = -Ilib

TEST_INCLUDES = -Iinclude $(INCLUDES)

STATIC_RULE = my_printf_static
STATIC_TARGET := libmy_printf_`uname -m`-`uname -s`.a

SHARED_RULE = my_printf_dynamic
SHARED_TARGET := libmy_printf_`uname -m`-`uname -s`.so

all: $(STATIC_TARGET) $(SHARED_TARGET)

.PHONY: $(STATIC_RULE)
STATIC_RULE: $(STATIC_TARGET)

.PHONY: $(SHARED_RULE)
SHARED_RULE: $(SHARED_TARGET)

$(DOBJ_DIR)/%.o: src/%.c | $(DOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SOBJ_DIR)/%.o: src/%.c | $(SOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(STATIC_TARGET): $(SOBJ) $(LIB)
	$(AR) rcs $(STATIC_TARGET) $(SOBJ) $(LIB)
	ranlib $(STATIC_TARGET)

$(SHARED_TARGET): $(DOBJ) $(LIB)
	$(CC) -shared $(CFLAGS) -o $(SHARED_TARGET) $(DOBJ) $(LIB)

$(DOBJ_DIR) $(SOBJ_DIR):
	@mkdir $@

$(LIB): $(LIB_DIR)
	make -C $(LIB_DIR)

.PHONY: test
test: tests/test
	./tests/test

tests/test: tests/tests.c tests/main.c $(STATIC_TARGET) $(LIB) 
	$(CC) $(CFLAGS) $(TEST_INCLUDES) $^ -o $@

.PHONY: re
re: fclean all
	make -C $(LIB_DIR) re

.PHONY: clean
clean:
	rm -r $(SOBJ_DIR) $(DOBJ_DIR)
	make -C $(LIB_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(STATIC_TARGET) $(SHARED_TARGET)
	make -C $(LIB_DIR) fclean
