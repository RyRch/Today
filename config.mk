SRC	=	src/main.c\
		src/option.c

LIB =	lib/is_num.c\
		lib/ft_strcat.c\
		lib/ft_strcmp.c\
		lib/ft_strcpy.c\
		lib/ft_strdup.c\
		lib/ft_strlen.c\
		lib/str_to_tab.c\
		lib/tab_to_str.c


NAME =	libmy.a

BIN	=	todo

CFLAGS	+=	-Wall -Werror -Wextra -I./icl -g3

CC	=	gcc

RM	=	rm -rf

OBJ	=	$(SRC:.c=.o)
