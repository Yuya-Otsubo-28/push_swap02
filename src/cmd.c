/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:11 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/24 16:48:09 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return ("sa");
	return ("sb");
}

char	*rotate(t_pslist **stack, t_name name)
{
	(*stack)->is_top = false;
	*stack = (*stack)->next;
	(*stack)->is_top = true;
	if (name == A)
		return ("ra");
	return ("rb");
}

char	*rev_rotate(t_pslist **stack, t_name name)
{
	(*stack)->is_top = false;
	*stack = (*stack)->prev;
	(*stack)->is_top = true;
	if (name == A)
		return ("rra");
	return ("rrb");
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
		return ("pa");
	return ("pb");
}