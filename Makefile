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

SRCLIBFILES = \
							append_char.c \
							assign_and_free.c \
							bool.c \
							char_in_str.c \
							debug.c \
							fail.c \
							int_in_arr.c \
							int_length.c \
							is_int.c \
							last_n_chars.c \
							linkedlist1.c \
							linkedlist2.c \
							linkedlist3.c \
							linkedlist4.c \
							linkedlist.c \
							linkedlist_debug.c \
							linkedlist_free.c \
							linkedlist_iter.c \
							linkedlist_str_concat.c \
							linkedlist_zip.c \
							my_calloc.c \
							my_getnbr.c \
							my_itoa.c \
							my_itoa_base.c \
							my_memcpy.c \
							my_memset.c \
							my_putchar.c \
							my_put_nbr.c \
							my_put_nbr_base.c \
							my_puterr.c \
							my_putstr.c \
							my_readfile.c \
							my_readline.c \
							my_readnchars.c \
							my_strcat.c \
							my_strcmp.c \
							my_strcpy.c \
							my_strlen.c \
							my_strncmp.c \
							my_strnew.c \
							my_strnpush.c \
							my_strpush.c \
							my_strstr.c \
							my_str_to_wordtab.c \
							noop.c \
							paths.c \
							set_to.c \
							str_eq.c \
							stringt.c \
							string_concat.c \
							units.c

OUT =	my_printf

CFLAGS = -g -Werror -Wall -Wextra
CC = gcc
AR = ar

SRC = $(patsubst %,src/%,$(SRCFILES))
SOBJ_DIR =  .static_obj
SOBJ :=  $(SRC:src/%.c=$(SOBJ_DIR)/%.o)
DOBJ_DIR =  .shared_obj
DOBJ :=  $(SRC:src/%.c=$(DOBJ_DIR)/%.o)

LIB_DIR = lib
SRCLIB = $(patsubst %,lib/%,$(SRCLIBFILES))
DOBJLIB = $(SRCLIB:$(LIB_DIR)/%.c=$(DOBJ_DIR)/%.o)
SOBJLIB = $(SRCLIB:$(LIB_DIR)/%.c=$(SOBJ_DIR)/%.o)

INCLUDES = -Ilib

TEST_INCLUDES = -Iinclude $(INCLUDES)

STATIC_RULE = my_printf_static
STATIC_TARGET := libmy_printf_`uname -m`-`uname -s`.a

DYNAMIC_RULE = my_printf_dynamic
DYNAMIC_TARGET := libmy_printf_`uname -m`-`uname -s`.so

.PHONY: all re clean fclean

all: $(STATIC_TARGET) $(SHARED_TARGET)

$(DYNAMIC_TARGET): $(DOBJ) $(DOBJLIB)
	$(CC) -shared $(CFLAGS) $(INCLUDES) -o $(SHARED_TARGET) $(DOBJ) $(DOBJLIB)

$(STATIC_TARGET): $(SOBJ) $(SOBJLIB)
	$(AR) rcs $(STATIC_TARGET) $(SOBJ) $(SOBJLIB)
	ranlib $(STATIC_TARGET)

$(SOBJ_DIR)/%.o: src/%.c | $(SOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SOBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(SOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(DOBJ_DIR)/%.o: src/%.c | $(DOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DOBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(DOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DOBJ_DIR) $(SOBJ_DIR):
	@mkdir $@

test: tests/test
	./tests/test

tests/test: tests/tests.c tests/main.c $(STATIC_TARGET) $(SLIB) 
	$(CC) $(CFLAGS) $(TEST_INCLUDES) $^ -o $@

re: fclean all
	make -C $(LIB_DIR) re

clean:
	rm -r $(SOBJ_DIR) $(DOBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(STATIC_TARGET) $(SHARED_TARGET)
	make -C $(LIB_DIR) fclean
