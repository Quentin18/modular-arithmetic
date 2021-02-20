CC = gcc
CFLAGS = -Wall -ansi -pedantic
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIB = libmod.a

all: $(LIB)

$(LIB): $(OBJ)
	ar cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.depend:
	$(CC) -MM $(SRC) > $@

-include .depend

clean:
	rm -f $(OBJ) $(LIB)

.PHONY: clean
