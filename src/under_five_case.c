/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:31 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/11 18:19:49 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	opt_sort_2(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	if (name == A)
		sort_2(stack, name, res);
	else if ((*stack)->num < (*stack)->next->num)
		sort_1_2(stack, sub_stack, name, res);
	else
		sort_2_1(stack, sub_stack, name, res);
}

static void	opt_sort_3(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	if (name == A)
		sort_3(stack, name, res);
	else if ((*stack)->num < (*stack)->next->num && \
			(*stack)->next->num < (*stack)->prev->num)
		sort_1_2_3(stack, sub_stack, name, res);
	else if ((*stack)->num < (*stack)->next->num && \
			(*stack)->next->num > (*stack)->prev->num && \
			(*stack)->num < (*stack)->prev->num)
		sort_1_3_2(stack, sub_stack, name, res);
	else if ((*stack)->num > (*stack)->next->num && \
			(*stack)->next->num < (*stack)->prev->num && \
			(*stack)->num < (*stack)->prev->num)
		sort_2_1_3(stack, sub_stack, name, res);
	else if ((*stack)->num < (*stack)->next->num && \
			(*stack)->next->num > (*stack)->prev->num && \
			(*stack)->num > (*stack)->prev->num)
		sort_2_3_1(stack, sub_stack, name, res);
	else if ((*stack)->num > (*stack)->next->num && \
			(*stack)->next->num < (*stack)->prev->num && \
			(*stack)->num > (*stack)->prev->num)
		sort_3_1_2(stack, sub_stack, name, res);
	else if ((*stack)->num > (*stack)->next->num && \
			(*stack)->next->num > (*stack)->prev->num)
		sort_3_2_1(stack, sub_stack, name, res);
}

static void	opt_sort_4(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	int	most_small;
	int	next_small;

	if (name == A)
	{
		sort_4(stack, name, res);
		return ;
	}
	get_small_nums(*stack, &most_small, &next_small, 4);
	while ((*stack)->num != most_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	while ((*stack)->num != next_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	opt_sort_2(stack, sub_stack, name, res);
}

static void	opt_sort_5(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	int	most_small;
	int	next_small;

	if (name == A)
	{
		sort_5(stack, name, res);
		return ;
	}
	get_small_nums(*stack, &most_small, &next_small, 5);
	while ((*stack)->num != most_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	while ((*stack)->num != next_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	opt_sort_3(stack, sub_stack, name, res);
}

void	under_five_case(t_stacks *stacks, int size, t_name name, t_list **res)
{
	if (size == 2)
		opt_sort_2(stacks->stack_1, stacks->stack_2, name, res);
	else if (size == 3)
		opt_sort_3(stacks->stack_1, stacks->stack_2, name, res);
	else if (size == 4)
		opt_sort_4(stacks->stack_1, stacks->stack_2, name, res);
	else if (size == 5)
		opt_sort_5(stacks->stack_1, stacks->stack_2, name, res);
	return ;
}
