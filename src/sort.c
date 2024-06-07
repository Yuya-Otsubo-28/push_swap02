/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:46:58 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/02 17:09:00 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	__print_stack(t_pslist *stack)
{
	int	size;
	int	i;

	if (!stack)
	{
		printf("stack is empty\n"); fflush(stdin);
	}
	i = 0;
	size = get_stack_size(stack);
	while (i++ < size)
	{
		printf("%d\n", stack->num); fflush(stdin);
		stack = stack->next;
	}
	printf("--------------------\n"); fflush(stdin);
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

int	get_stack_size(t_pslist *stack)
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
	return (min + (max - min) / 2);
}

static int	make_stack_b(t_pslist **stack_a, t_pslist **stack_b, t_list **res, int a_size)
{
	int			middle;
	int			i;
	int			count;

	middle = a_size / 2;
	i = 0;
	count = 0;
	while (i < a_size)
	{
		if ((*stack_a)->num < middle)
		{
			ft_lstadd_back(res, ft_lstnew(push(stack_a, stack_b, B)));
			count++;
		}
		else
			ft_lstadd_back(res, ft_lstnew(rotate(stack_a, A)));
		i++;
	}
	return (count);
}

static int	push_half_to_a(t_pslist **stack_a, t_pslist **stack_b, t_list **res)
{
	int	middle;
	int	b_size;
	int	i;
	int	count;

	middle = get_middle(*stack_b);
	b_size = get_stack_size(*stack_b);
	i = 0;
	count = 0;
	while (i++ < b_size)
	{
		if ((*stack_b)->num > middle)
			ft_lstadd_back(res, ft_lstnew(push(stack_b, stack_a, A)));
		else
		{
			count++;
			ft_lstadd_back(res, ft_lstnew(rotate(stack_b, B)));
		}
	}
	return (count);
}

static int	proc_of_leaf(t_pslist **stack_a, t_pslist **stack_b, t_list **res, int b_size)
{
	// int	i;
	// int	push_nums;

	// if (b_size > 3 && !is_sorted(*stack_b))
	// 	push_nums = b_size - 2;
	// else
	// 	push_nums = b_size;
	under_five_case(stack_b, stack_a, b_size, B, res);
	// i = 0;
	// while (i++ < push_nums)
	// {
	// 	ft_lstadd_back(res, ft_lstnew(push(stack_b, stack_a, A)));
	// 	ft_lstadd_back(res, ft_lstnew(rotate(stack_a, A)));
	// }
	*stack_b = NULL;
	return (b_size);
}


static int	recusive_sort(t_pslist **stack_a, t_pslist **stack_b, t_list **res, int pre_size)
{
	int	b_size;
	int	sorted_size;
	int	i;

	if (!*stack_b && is_sorted(*stack_a))
		return (pre_size);
	b_size = get_stack_size(*stack_b);
	if (b_size > 0 && b_size <= 5)
		return (proc_of_leaf(stack_a, stack_b, res, b_size));
	if (!b_size)
		b_size = make_stack_b(stack_a, stack_b, res, pre_size);
	else
		b_size = push_half_to_a(stack_a, stack_b, res);
	// printf("first\n"); fflush(stdin);
	// __print_stack(*stack_a);
	// __print_stack(*stack_b);
	sorted_size = recusive_sort(stack_a, stack_b, res, b_size);
	// printf("second\nsorted_size:%d\npre_size: %d\n", sorted_size, pre_size); fflush(stdin);
	// __print_stack(*stack_a);
	// __print_stack(*stack_b);
	i = 0;
	while (sorted_size + i < pre_size)
	{
		ft_lstadd_back(res, ft_lstnew(push(stack_a, stack_b, B)));
		i++;
	}
	recusive_sort(stack_a, stack_b, res, i);
	return (pre_size);
}

void	sort(t_pslist **stack_a, t_list **res)
{
	int			a_size;
	t_pslist	*stack_b;

	stack_b = NULL;
	a_size = get_stack_size(*stack_a);
	if (a_size <= 5)
	{
		under_five_case(stack_a, NULL, a_size, A, res);
		ft_lstadd_back(res, ft_lstnew("end"));
		free_stack(stack_b);
		return ;
	}
	stack_b = NULL;
	recusive_sort(stack_a, &stack_b, res, a_size);
	ft_lstadd_back(res, ft_lstnew("end"));
	free_stack(stack_b);
}
