DIR	=	src

SRC	=	$(DIR)/main.c\
		$(DIR)/str_to_arr.c\
		$(DIR)/option.c\
		$(DIR)/util.c

BIN	=	todo

CFLAGS	+=	-Wall -Werror -Wextra -I./icl -g

DFLAGS	=	-g3

CC	=	gcc

RM	=	rm -rf

OBJ	=	$(SRC:.c=.o)
