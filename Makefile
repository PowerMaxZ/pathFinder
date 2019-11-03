INC = pathFinder.h
INCF = inc/pathFinder.h

SRC = \
isletter.c \
error_handler.c \
main.c \
error_number.c

SRCF = \
src/isletter.c \
src/error_handler.c \
src/main.c \
src/error_number.c

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

all: install clean
install:
	@cd libmx && make -f Makefile install
	@cp $(SRCF) .
	@cp $(INCF) .
	@clang $(CFLAGS) $(SRC) libmx/libmx.a $(INC)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf a.out
clean:
	@cd libmx && make -f Makefile clean
	@rm $(SRC)
	@rm $(INC)
	@rm pathFinder.h.gch
reinstall: uninstall all
