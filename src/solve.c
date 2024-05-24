/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:46:58 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/24 17:05:50 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	under_five_cases(t_pslist *stack, t_list **res, int	size, t_name name)
{
	if (size == 1)
		ft_lstadd_back(res, ft_lstnew(""));
	else if (size == 2)
		solve_2(stack, name, res);
	else if (size == 3)
		solve_3(stack, name, res);
	else if (size == 4)
		solve_4(stack, name, res);
	else if (size == 5)
		solve_5(stack, name, res);
	return ;
}

void	solve(t_data *data, t_list **res)
{
	*res = NULL;

	if (data->total_size <= 5)
	{
		under_five_cases(data->stack_a, res, data->total_size, A);
		return ;
	}
	while (!is_sorted(data->stack_a))
	{
		
	}
}