NAME = push_swap
BONUS_NAME = checker
INCLUDES = push_swap.h
BINCLUDES = bonus/checker_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c push.c swap.c rotate.c reverse_rotate.c \
	utils.c parse.c atol.c split.c \
	index.c algo.c free.c calloc.c ft_putstr.c sort_five.c

BSRC = bonus/atol_bonus.c bonus/ft_putstr_bonus.c bonus/parse_bonus.c bonus/split_bonus.c \
	bonus/calloc_bonus.c bonus/get_next_line_bonus.c bonus/push_bonus.c bonus/strcmp_bonus.c \
	bonus/get_next_line_utils_bonus.c bonus/reverse_rotate_bonus.c bonus/swap_bonus.c \
	bonus/free_bonus.c bonus/main_bonus.c bonus/rotate_bonus.c bonus/utils_bonus.c bonus/store_utils_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ) $(BINCLUDES)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BONUS_NAME)

bonus/%.o: bonus/%.c $(BINCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean