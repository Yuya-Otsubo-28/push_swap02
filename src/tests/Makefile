CFLAGS= -Wall -Wextra -Werror
INCLUDE= -I../../ -I../../libft
LIBFT= ../libft.a

ary_init: ../ary_init.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) $< -o $@

compress: ../compress.c ../ary_init.c
	cc $(CFLAGS) $(INCLUDE) $(LIBFT) ../compress.c ../ary_init.c -o $@
