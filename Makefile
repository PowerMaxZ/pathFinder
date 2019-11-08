INC = pathFinder.h
INCF = inc/pathFinder.h

SRC = \
mx_isletter.c \
main.c \
mx_get_matrix.c \
mx_add_edge.c \
mx_arr_size.c \
mx_create_graph.c \
mx_ctoi.c \
mx_get_graph_matrix.c \
mx_get_index_island.c \
mx_get_path_bt_islands.c \
mx_get_weight_path.c \
mx_print_graph.c \
mx_print_path.c \
mx_new_adj_list_node.c \
mx_check_text.c \
mx_check_text_value.c \
mx_isnum.c \
mx_numlen.c \
mx_get_paths.c \
mx_isword.c \
mx_get_length_bt_isl.c \
mx_printerr.c \
mx_printerror.c \
mx_isdigit.c \
mx_file_to_str.c \
mx_itoa.c \
mx_atoi.c

SRCF = \
src/mx_isletter.c \
src/main.c \
src/mx_get_matrix.c \
src/mx_add_edge.c \
src/mx_arr_size.c \
src/mx_create_graph.c \
src/mx_ctoi.c \
src/mx_get_graph_matrix.c \
src/mx_get_index_island.c \
src/mx_get_path_bt_islands.c \
src/mx_get_weight_path.c \
src/mx_print_graph.c \
src/mx_print_path.c \
src/mx_new_adj_list_node.c \
src/mx_check_text.c \
src/mx_check_text_value.c \
src/mx_isnum.c \
src/mx_numlen.c \
src/mx_get_paths.c \
src/mx_isword.c \
src/mx_get_length_bt_isl.c \
src/mx_printerr.c \
src/mx_printerror.c \
src/mx_isdigit.c \
src/mx_file_to_str.c \
src/mx_itoa.c \
src/mx_atoi.c

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

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
