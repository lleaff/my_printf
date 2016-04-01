SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

OUT =	my_printf

CFLAGS = -g -Werror -Wall -Wextra
CC = gcc

LIB = libmy.a
LIB_DIR = lib

all: $(OUT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

lib: $(LIB)
	make -f $(LIB_DIR)/Makefile

clean:
	rm -f $(OBJ)
	make -f $(LIB_DIR)/Makefile clean

fclean: clean
	rm -f $(OUT)
	make -f $(LIB_DIR)/Makefile fclean
