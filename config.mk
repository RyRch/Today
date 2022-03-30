SRC	=	src/main.c\
		src/option.c\
		src/list.c

LIB =	lib/is_num.c\
		lib/ft_strcat.c\
		lib/ft_strcmp.c\
		lib/ft_strcpy.c\
		lib/ft_strdup.c\
		lib/ft_strlen.c\
		lib/ft_strncmp.c\
		lib/str_to_tab.c\
		lib/tab_to_str.c\
		lib/ft_itoa.c\
		lib/ft_strncpy.c

NAME =	libmy.a

BIN	=	today

CFLAGS	+= -g3	

CC	=	gcc

RM	=	rm -rf

OBJ	=	$(SRC:.c=.o)

LOBJ =	$(LIB:.c=.o)
