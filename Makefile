CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

M_SRCS = Mandatory-part/push_swap.c \
	Mandatory-part/checking_and_parsing/check_all.c \
	Mandatory-part/checking_and_parsing/check_duplicate.c \
	Mandatory-part/checking_and_parsing/check_input.c \
	Mandatory-part/checking_and_parsing/check_overflow.c \
	Mandatory-part/checking_and_parsing/parsing.c \
	Mandatory-part/Helper_Functions/ft_atoi.c \
	Mandatory-part/Helper_Functions/ft_split.c \
	Mandatory-part/Helper_Functions/helpers.c \
	Mandatory-part/Helper_Functions/helpers2.c \
	Mandatory-part/Helper_Functions/indexing.c \
	Mandatory-part/Linked-Lists/Linked_lists.c \
	Mandatory-part/Linked-Lists/Linked_lists2.c \
	Mandatory-part/Operations/operation_push.c \
	Mandatory-part/Operations/operation_rotate.c \
	Mandatory-part/Operations/operation_rrotate.c \
	Mandatory-part/Operations/operation_swap.c \
	Mandatory-part/Sorting/sort_all.c \
	Mandatory-part/Sorting/sort_five.c \
	Mandatory-part/Sorting/sort_three.c

B_SRCS = Bonus-part/checker.c \
	Bonus-part/bonus_helpers.c \
	Bonus-part/get_next_line.c \
	Bonus-part/get_next_line_utils.c \
	Bonus-part/checking_and_parsing/check_all.c \
	Bonus-part/checking_and_parsing/check_duplicate.c \
	Bonus-part/checking_and_parsing/check_input.c \
	Bonus-part/checking_and_parsing/check_overflow.c \
	Bonus-part/checking_and_parsing/parsing.c \
	Bonus-part/Helper_Functions/ft_atoi.c \
	Bonus-part/Helper_Functions/ft_split.c \
	Bonus-part/Helper_Functions/helpers.c \
	Bonus-part/Helper_Functions/helpers2.c \
	Bonus-part/Helper_Functions/indexing.c \
	Bonus-part/Linked-Lists/Linked_lists.c \
	Bonus-part/Linked-Lists/Linked_lists2.c \
	Bonus-part/Operations/operation_push.c \
	Bonus-part/Operations/operation_rotate.c \
	Bonus-part/Operations/operation_rrotate.c \
	Bonus-part/Operations/operation_swap.c

M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJS)
	$(CC) $(CFLAGS) $(M_OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(M_OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
