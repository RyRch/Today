include config.mk

all:	$(BIN)

$(BIN):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(BIN)

valgrind:
	valgrind ./$(BIN) res/task.txt

re: fclean all

.PHONY: all clean fclean re
