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

$(OUT): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

$(LIB): $(LIB_DIR)
	make -C $(LIB_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(OUT)
	make -C $(LIB_DIR) fclean
