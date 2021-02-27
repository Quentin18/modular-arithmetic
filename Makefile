LIB_DIR = lib
SRC_DIR = src

all:
	cd $(LIB_DIR) && make
	cd $(SRC_DIR) && make

# Docs
docs:
	doxygen Doxyfile
	xdg-open docs/html/index.html

cleandocs:
	rm -r docs

clean:
	cd $(LIB_DIR) && make clean
	cd $(SRC_DIR) && make clean

.PHONY: clean
