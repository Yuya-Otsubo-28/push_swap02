CFLAGS= -Wall -Wextra -Werror
INCLUDE= -I../ -I../libft/
LIBFT= ../src/libft.a

ary_init: ../src/ary_init.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) $< -o $@

compress: ../src/compress.c ../src/ary_init.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) ../src/compress.c ../src/ary_init.c -o $@

stack_init : ../src/stack_init.c ../src/ary_init.c ../src/compress.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) ../src/stack_init.c ../src/compress.c ../src/ary_init.c -o $@

under_five : ../src/stack_init.c ../src/ary_init.c ../src/compress.c ../src/solve_2_5.c ../src/print_result.c ../src/cmd.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) ../src/stack_init.c ../src/compress.c ../src/ary_init.c ../src/solve_2_5.c ../src/print_result.c ../src/cmd.c -o $@

