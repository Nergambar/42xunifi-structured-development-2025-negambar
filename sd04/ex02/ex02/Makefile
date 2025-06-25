CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
SRC = src/main.c src/contact.c src/contact_manager.c src/utils.c
OBJ = $(SRC:.c=.o)
NAME = contact_manager

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re