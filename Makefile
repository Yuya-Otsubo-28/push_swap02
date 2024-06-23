NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INCLUDES = -I./ -I./libft
SRCS = ./src/ary_init.c \
		./src/ary_init_utils.c \
		./src/cmd.c \
		./src/compress.c \
		./src/print_result.c \
		./src/push_swap.c \
		./src/sort_2_5.c \
		./src/sort_2_5_utils.c \
		./src/sort.c \
		./src/sort_utils.c \
		./src/stack_init.c \
		./src/under_five_case.c \
		./src/opt_sort_utils1.c \
		./src/opt_sort_utils2.c
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
