include config.mk

all:	$(NAME) $(BIN) 

$(NAME):
	$(CC) $(CFLAGS) -c $(LIB)
	ar rc $(NAME) *.o

$(BIN):	$(OBJ)
	$(CC) $(OBJ) $(NAME) $(CFLAGS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) *.o

fclean:	clean
	$(RM) $(BIN)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
