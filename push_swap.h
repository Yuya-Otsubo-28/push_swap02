/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/23 21:01:24 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0

# define A 1
# define B -1

typedef int	t_bool;
typedef int	t_name;

typedef struct s_pslist {
	int				num;
	t_bool			is_top;
	struct s_pslist	*next;
	struct s_pslist	*prev;
}	t_pslist;

typedef struct s_stacks {
	t_pslist	**stack_1;
	t_pslist	**stack_2;
}	t_stacks;

/*********************************/
/*                               */
/*       ary_init_utils.c        */
/*                               */
/*********************************/

t_bool		is_int_range(int res, int flag, char c);

t_bool		is_valid_arg(char *arg);

t_bool		is_duplicated(int *ary, int size);

/*********************************/
/*                               */
/*       	ary_init.c	         */
/*                               */
/*********************************/

int			*ary_init(int argc, char *argv[], int *size);

/*********************************/
/*                               */
/*       		cmd.c	         */
/*                               */
/*********************************/

char		*swap(t_pslist **stack, t_name name);

char		*rotate(t_pslist **stack, t_name name);

char		*rev_rotate(t_pslist **stack, t_name name);

char		*push(t_pslist **stack1, t_pslist **stack2, t_name name);

/*********************************/
/*                               */
/*           compress.c          */
/*                               */
/*********************************/

int			*compress(int *input, int size);

/*********************************/
/*                               */
/*      opt_sort_utils1.c        */
/*                               */
/*********************************/

void		sort_1_3_2(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

void		sort_2_1_3(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

void		sort_2_3_1(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

void		sort_3_1_2(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

void		sort_3_2_1(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

/*********************************/
/*                               */
/*      opt_sort_utils2.c        */
/*                               */
/*********************************/

void		sort_1_2_3(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

void		sort_1_2(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

void		sort_2_1(t_pslist **stack, t_pslist **sub_stack, \
					t_name name, t_list **res);

/*********************************/
/*                               */
/*         print_result.c        */
/*                               */
/*********************************/

t_bool		print_result(t_list *res);

/*********************************/
/*                               */
/*           sort_2_5.c          */
/*                               */
/*********************************/

void		sort_2(t_pslist **stack, t_name name, t_list **res);

void		sort_3(t_pslist **stack, t_name name, t_list **res);

void		sort_4(t_pslist **stack, t_name name, t_list **res);

void		sort_5(t_pslist **stack, t_name name, t_list **res);

/*********************************/
/*                               */
/*        sort_2_5_utils.c       */
/*                               */
/*********************************/

void		rotate_untill_n(t_pslist **stack, t_name name, t_list **res, int n);

/*********************************/
/*                               */
/*         sort_utils.c          */
/*                               */
/*********************************/

t_bool		is_sorted(t_pslist *stack);

int			get_middle(t_pslist *stack);

int			get_stack_size(t_pslist *stack);

void		get_small_nums(t_pslist *stack, int *most_small, \
					int *next_small, int size);

/*********************************/
/*                               */
/*             sort.c            */
/*                               */
/*********************************/

void		sort(t_pslist **stack_a, t_list **res);

/*********************************/
/*                               */
/*          stack_init.c         */
/*                               */
/*********************************/

t_pslist	**stack_init(int *input, int size);

/*********************************/
/*                               */
/*       under_five_cases.c      */
/*                               */
/*********************************/

void		under_five_case(t_stacks *stacks, int size, \
						t_name name, t_list **res);

/*********************************/
/*                               */
/*           push_swap.c         */
/*                               */
/*********************************/

t_pslist	*free_stack(t_pslist *stack_a);
#endif
