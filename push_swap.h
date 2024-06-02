/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/02 16:41:16 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

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

void		solve(t_pslist *stack_a, t_list **res);

void		solve_2(t_pslist *stack, t_name name, t_list **res);

void		solve_3(t_pslist *stack, t_name name, t_list **res);

void		solve_4(t_pslist *stack, t_name name, t_list **res);

void		solve_5(t_pslist *stack, t_name name, t_list **res);

t_bool		is_sorted(t_pslist *stack);

void		print_result(t_list *res);

#endif