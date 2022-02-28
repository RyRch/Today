DIR	=	src

SRC	=	$(DIR)/main.c\
		$(DIR)/str_to_tab.c

BIN	=	todo

CFLAGS	+=	-Wall -Werror -Wextra -I./icl -g

DFLAGS	=	-g3

CC	=	gcc

RM	=	rm -rf

OBJ	=	$(SRC:.c=.o)
