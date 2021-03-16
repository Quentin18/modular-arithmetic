CC = gcc
CFLAGS = -Wall -ansi -pedantic
LIB_DIR = ../lib
INCFLAGS = -I$(LIB_DIR)
LIBFLAGS = -L$(LIB_DIR) -lmod -lrt -lm
LIB = $(LIB_DIR)/libmod.a
EXEC = tests.out

$(EXEC): tests.c $(LIB)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(LIB):
	cd $(LIB_DIR) && make

clean:
	rm -f $(EXEC)

.PHONY: clean
