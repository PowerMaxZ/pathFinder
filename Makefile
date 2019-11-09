INC = pathFinder.h
INCF = inc/pathFinder.h

NAME = pathfinder

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

OBJF = obj/mx_isletter.o \
obj/main.o \
obj/mx_get_matrix.o \
obj/mx_add_edge.o \
obj/mx_arr_size.o \
obj/mx_create_graph.o \
obj/mx_ctoi.o \
obj/mx_get_graph_matrix.o \
obj/mx_get_index_island.o \
obj/mx_get_path_bt_islands.o \
obj/mx_get_weight_path.o \
obj/mx_print_graph.o \
obj/mx_print_path.o \
obj/mx_new_adj_list_node.o \
obj/mx_check_text.o \
obj/mx_check_text_value.o \
obj/mx_isnum.o \
obj/mx_numlen.o \
obj/mx_get_paths.o \
obj/mx_isword.o \
obj/mx_get_length_bt_isl.o \
obj/mx_printerr.o \
obj/mx_printerror.o \
obj/mx_isdigit.o \
obj/mx_file_to_str.o \
obj/mx_itoa.o \
obj/mx_atoi.o

OBJ = mx_isletter.o \
main.o \
mx_get_matrix.o \
mx_add_edge.o \
mx_arr_size.o \
mx_create_graph.o \
mx_ctoi.o \
mx_get_graph_matrix.o \
mx_get_index_island.o \
mx_get_path_bt_islands.o \
mx_get_weight_path.o \
mx_print_graph.o \
mx_print_path.o \
mx_new_adj_list_node.o \
mx_check_text.o \
mx_check_text_value.o \
mx_isnum.o \
mx_numlen.o \
mx_get_paths.o \
mx_isword.o \
mx_get_length_bt_isl.o \
mx_printerr.o \
mx_printerror.o \
mx_isdigit.o \
mx_file_to_str.o \
mx_itoa.o \
mx_atoi.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cd libmx && make -f Makefile install
	@cp $(SRCF) .
	@cp $(INCF) .
	@clang $(CFLAGS) -c $(SRC)
	@mkdir obj
	@mv $(OBJ) ./obj
	@clang $(CFLAGS) $(OBJF) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO)
	@rm -rf ./obj
	@rm -rf $(NAME)
clean:
	@cd libmx && make -f Makefile clean
	@rm $(SRC)
	@rm $(INC)
reinstall: uninstall all
