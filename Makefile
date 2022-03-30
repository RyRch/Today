include config.mk

all:	$(NAME) $(BIN) 

$(NAME): $(LOBJ)
	ar rc $(NAME) $(LOBJ)

$(BIN):	$(OBJ)
	$(CC) $(OBJ) $(NAME) $(CFLAGS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(LOBJ)

fclean:	clean
	$(RM) $(BIN)
	$(RM) $(NAME)

install: all
	touch ~/.today
	echo '0.0:open tdy' > ~/.today

re: fclean all

.PHONY: all clean fclean re
