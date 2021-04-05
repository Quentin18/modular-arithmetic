CC = gcc
CFLAGS = -Wall -ansi -pedantic

LIB_DIR = ./lib
SRC_DIR = ./src
BUILD_DIR = ./build

INCFLAGS = -I$(LIB_DIR)
LIBFLAGS = -L$(LIB_DIR) -lmod

LIB = $(LIB_DIR)/libmod.a
BIN = \
	$(BUILD_DIR)/extendedGcdInt.out \
	$(BUILD_DIR)/extendedGcdPoly.out \
	$(BUILD_DIR)/evalPoly.out \
	$(BUILD_DIR)/multipointEvalPoly.out \
	$(BUILD_DIR)/euclideanDivisionPoly.out \
	$(BUILD_DIR)/interpolationPoly.out

all: $(BIN)

$(LIB):
	cd $(LIB_DIR) && make

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/extendedGcdInt.out: $(SRC_DIR)/mainExtendedGcdInt.c $(LIB) $(BUILD_DIR)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(BUILD_DIR)/extendedGcdPoly.out: $(SRC_DIR)/mainExtendedGcdPoly.c $(LIB) $(BUILD_DIR)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(BUILD_DIR)/evalPoly.out: $(SRC_DIR)/evalPoly.c $(LIB) $(BUILD_DIR)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(BUILD_DIR)/multipointEvalPoly.out: $(SRC_DIR)/multipointEvalPoly.c $(LIB) $(BUILD_DIR)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(BUILD_DIR)/euclideanDivisionPoly.out: $(SRC_DIR)/euclideanDivisionPoly.c $(LIB) $(BUILD_DIR)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

$(BUILD_DIR)/interpolationPoly.out: $(SRC_DIR)/interpolationPoly.c $(LIB) $(BUILD_DIR)
	$(CC) $< $(CFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $@

docs:
	doxygen Doxyfile
	xdg-open docs/html/index.html

cleandocs:
	rm -r docs

clean:
	rm -rf $(BUILD_DIR)
	cd $(LIB_DIR) && make clean

.PHONY: clean
