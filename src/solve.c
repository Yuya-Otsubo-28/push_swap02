/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:46:58 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/30 19:17:11 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	under_five_case(t_pslist *stack, int size, t_name name, t_list **res)
{
	if (size == 2)
		solve_2(stack, name, res);
	else if (size == 3)
		solve_3(stack, name, res);
	else if (size == 4)
		solve_4(stack, name, res);
	else if (size == 5)
		solve_5(stack, name, res);
	return ;
}

t_bool	is_sorted(t_pslist *stack)
{
	while (1)
	{
		if (stack->next->is_top)
			break ;
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static int	get_stack_size(t_pslist *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (1)
	{
		size++;
		if (stack->next->is_top)
			break ;
		stack = stack->next;
	}
	return (size);
}

static int	get_middle(t_pslist *stack)
{
	int	max;
	int	min;

	max = INT_MIN;
	min = INT_MAX;
	while (1)
	{
		if (stack->next->is_top)
			break ;
		if (stack->num > max)
			max = stack->num;
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return ((max - min) / 2);
}

static int	divide_half(t_pslist **main_stack, t_pslist **sub_stack, t_name name)
{
	int	middle;
	
	middle = get_middle(*main_stack);
	while (1)
	{
		if ((*main_stack)->next->is_top)
			break ;
		if ((*main_stack)->num < middle)
			push(main_stack, sub_stack, name * -1);
		else
			rotate(main_stack, name);
		*main_stack = (*main_stack)->next;
	}
	return (middle);
}

static int	recusive_solve(t_pslist **stack_a, t_pslist **stack_b, t_list **res, int pre_size)
{
	int	middle;
	int	b_size;
	int	pushed_size;
	int	i;
	int	j;

	if (!stack_b && is_sorted(stack_a))
		return (0);
	
	// if (!stack_b)
	// 	middle = divide_half(stack_a, stack_b, A);
	// else
	// 	middle = divide_half(stack_b, stack_a, B);
	b_size = get_stack_size(*stack_b);
	if (b_size <= 5)
	{
		under_five_case(*stack_b, b_size, B, res);
		i = 0;
		while (i++ < b_size)
		{
			push(stack_b, stack_a, A);
			rotate(stack_a, A);
		}
		*stack_b = NULL;
		return (b_size);
	}
	recusive_solve(stack_a, stack_b, res, b_size);
	j = 0;
	while (pushed_size + j++ < pre_size)
		push(stack_a, stack_b, B);
	recusive_solve(stack_a, stack_b, res, j);
	return ;
}

void	solve(t_pslist *stack_a, t_list **res)
{
	int			a_size;
	t_pslist	*stack_b;

	a_size = get_stack_size(stack_a);
	if (a_size <= 5)
	{
		under_five_case(stack_a, a_size, A, res);
		return ;
	}
	stack_b = NULL;
	
	recusive_solve(&stack_a, &stack_b, res);
}