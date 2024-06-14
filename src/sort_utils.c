/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:39:49 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/14 09:49:02 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_bool	is_sorted(t_pslist *stack)
{
	while (1)
	{
		if (stack->next->is_top)
			break ;
		if (stack->num > stack->next->num)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
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

int	get_middle(t_pslist *stack)
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

void	get_small_nums(t_pslist *stack, int *most_small, \
		int *next_small, int size)
{
	int	i;

	*most_small = INT_MAX;
	*next_small = INT_MAX;
	i = 0;
	while (i++ < size)
	{
		if (stack->num <= *most_small)
			*most_small = stack->num;
		stack = stack->next;
	}
	while (i-- > 0)
	{
		if (stack->num > *most_small && stack->num <= *next_small)
			*next_small = stack->num;
		stack = stack->next;
	}
}
