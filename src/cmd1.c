/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:11 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/21 18:30:38 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// strjoinを作り変えて、第2引数がNULLの時はエラーにする.

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
		return (ft_strdup("ra\n"));
	return (ft_strdup("rb\n"));
}