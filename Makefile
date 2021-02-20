LIB_DIR = lib
SRC_DIR = src

all:
	cd $(LIB_DIR) && make
	cd $(SRC_DIR) && make

clean:
	cd $(LIB_DIR) && make clean
	cd $(SRC_DIR) && make clean

.PHONY: clean
