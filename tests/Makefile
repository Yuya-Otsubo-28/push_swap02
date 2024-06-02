CFLAGS= -Wall -Wextra -Werror
INCLUDE= -I./src -I./src/libft
LIBFT= ./src/libft.a

ary_init: ./src/ary_init.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) $< -o $@

compress: ./src/compress.c ./src/ary_init.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) ../compress.c ../ary_init.c -o $@

stack_init : ./src/stack_init.c ./src/ary_init.c ./src/compress.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) ../stack_init.c ../compress.c ../ary_init.c -o $@
