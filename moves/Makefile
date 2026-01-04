NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c push.c swap.c rotate.c reverse_rotate.c \
	utils.c parse.c atol.c split.c \
	index.c algo.c free.c calloc.c ft_putstr.c sort_five.c

BSRC = bonus/atol.c bonus/main.c bonus/free.c bonus/parse.c \
	bonus/reverse_rotate.c bonus/split.c bonus/swap.c bonus/calloc.c \
	bonus/ft_putstr.c bonus/push.c bonus/rotate.c bonus/strcmp.c \
	bonus/utils.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

reb: fclean bonus

.PHONY: clean