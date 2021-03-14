LIB_DIR = lib
SRC_DIR = src
LIB = $(LIB_DIR)/libmod.a

all: $(LIB)
	cd $(SRC_DIR) && make

$(LIB):
	cd $(LIB_DIR) && make

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
