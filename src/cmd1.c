/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:11 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/21 13:58:19 by yotsubo          ###   ########.fr       */
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
	
}