CC = gcc
CFLAGS = -Wall -ansi -pedantic
LIB_DIR = ../lib
INCFLAGS = -I$(LIB_DIR)
LIBFLAGS = -L$(LIB_DIR) -lmod
LIB = $(LIB_DIR)/libmod.a
SRC = $(wildcard *.c)
EXEC = $(SRC:.c=.out)

all: $(EXEC)

%.out: %.c $(LIB)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(LIB):
	cd $(LIB_DIR) && make

clean:
	rm -f *.out

.PHONY: clean
