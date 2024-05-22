/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:11 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:18 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

char	*swap(t_pslist **stack, t_name name)
{
	t_pslist	*tmp;

	tmp = (*stack)->next;
	(*stack)->next->next->prev = *stack;
	(*stack)->next = (*stack)->next->next;
	(*stack)->is_top = false;
	tmp->prev = (*stack)->prev;
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	tmp->prev->next = tmp;
	tmp->is_top = true;
	*stack = tmp;
	if (name == A)
		return (ft_strdup("sa\n"));
	return (ft_strdup("sb\n"));
}

char	*rotate(t_pslist **stack, t_name name)
{
	(*stack)->is_top = false;
	*stack = (*stack)->next;
	(*stack)->is_top = true;
	if (name == A)
		return (ft_strdup("ra\n"));
	return (ft_strdup("rb\n"));
}

char	*rev_rotate(t_pslist **stack, t_name name)
{
	(*stack)->is_top = false;
	*stack = (*stack)->prev;
	(*stack)->is_top = true;
	if (name == A)
		return (ft_strdup("rra\n"));
	return (ft_strdup("rrb\n"));
}

char	*push(t_pslist **stack1, t_pslist **stack2, t_name name)
{
	t_pslist *element;

	element = *stack1;
	(*stack1)->next->is_top = true;
	(*stack1)->next->prev = (*stack1)->prev;
	(*stack1)->prev->next = (*stack1)->next;
	*stack1 = (*stack1)->next;
	if (*stack2)
	{
		element->next = *stack2;
		element->prev = (*stack2)->prev;
		element->prev->next = element;
		(*stack2)->is_top = false;
		(*stack2)->prev = element;
	}
	else
	{
		element->next = element;
		element->prev = element;
	}
	*stack2 = element;
	if (name == A)
		return (ft_strdup("pa\n"));
	return (ft_strdup("pb\n"));
}