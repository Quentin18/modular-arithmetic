CC = gcc
CFLAGS = -Wall -ansi -pedantic
LIB_DIR = ../lib
INCFLAGS = -I$(LIB_DIR)
LIBFLAGS = -L$(LIB_DIR) -lmod
LIB = $(LIB_DIR)/libmod.a

all: ../extendedGcdInt.out ../extendedGcdPoly.out ../evalPoly.out ../multipointEvalPoly.out ../euclideanDivisionPoly.out ../interpolationPoly.out

../extendedGcdInt.out: $(LIB)
	$(CC) mainExtendedGcdInt.c $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

../extendedGcdPoly.out: $(LIB)
	$(CC) mainExtendedGcdPoly.c $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

../evalPoly.out: $(LIB)
	$(CC) evalPoly.c $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

../multipointEvalPoly.out: $(LIB)
	$(CC) multipointEvalPoly.c $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

../euclideanDivisionPoly.out: $(LIB)
	$(CC) euclideanDivisionPoly.c $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

../interpolationPoly.out: $(LIB)
	$(CC) interpolationPoly.c $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(LIB):
	cd $(LIB_DIR) && make

clean:
	cd .. && rm -f *.out

.PHONY: clean
