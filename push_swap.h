/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/08 14:35:50 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
#include "libft.h"

# define true 1
# define false 0

# define A 1
# define B -1

typedef int t_bool;
typedef int t_name;

typedef struct s_pslist {
	int				num;
	t_bool			is_top;
	struct s_pslist	*next;
	struct s_pslist	*prev;
} t_pslist ;

char		*swap(t_pslist **stack, t_name name);

char		*rotate(t_pslist **stack, t_name name);

char		*rev_rotate(t_pslist **stack, t_name name);

char		*push(t_pslist **stack1, t_pslist **stack2, t_name name);

t_pslist	**stack_init(int *input, int size);

int			*compress(int *input, int size);

int			*ary_init(int argc, char *argv[], int *size);

void		sort(t_pslist **stack_a, t_list **res);

void		sort_2(t_pslist **stack, t_name name, t_list **res);

void		sort_3(t_pslist **stack, t_name name, t_list **res);

void		sort_4(t_pslist **stack, t_name name, t_list **res);

void		sort_5(t_pslist **stack, t_name name, t_list **res);

t_bool		is_sorted(t_pslist *stack);

t_bool		print_result(t_list *res);

int			get_stack_size(t_pslist *stack);

t_pslist	*free_stack(t_pslist *stack_a);

void		under_five_case(t_pslist **stack, t_pslist **stack2, int size, t_name name, t_list **res);

void		get_small_nums(t_pslist *stack, int *most_small, int *next_small, int size);

/*********************************/
/*                               */
/*       ary_init_utils.c        */
/*                               */
/*********************************/

t_bool	is_int_range(int res, int flag, char c);

t_bool	is_valid_arg(char *arg);

t_bool	is_duplicated(int *ary, int size);

/*********************************/
/*                               */
/*      opt_sort_utils1.c        */
/*                               */
/*********************************/

void	sort_1_3_2(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

void	sort_2_1_3(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

void	sort_2_3_1(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

void	sort_3_1_2(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

void	sort_3_2_1(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

/*********************************/
/*                               */
/*      opt_sort_utils2.c        */
/*                               */
/*********************************/

void	sort_1_2_3(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

void	sort_1_2(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

void	sort_2_1(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res);

#endif
