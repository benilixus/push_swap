NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c push.c swap.c rotate.c reverse_rotate.c \
      utils.c parse.c fill_stack.c atol.c split.c \
      index.c algo.c free.c calloc.c ft_putstr.c sort_five.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all