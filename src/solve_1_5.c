/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/15 19:05:51 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

char	*solve_2(t_data *data)
{
	int	head;
	int tail;

	head = (*(data->stack_a))->num;
	tail = (*(data->stack_a))->next->num;
	if (head > tail)
		return (ft_strdup("ra\n"));
	return (ft_strdup(""));
}

// ft_strdup()をそのままreturnしてるから、連結させる時のNULLチェクが必要

char	*solve_3(t_data *data)
{
	int	head;
	int	middle;
	int tail;

	head = (*(data->stack_a))->num;
	middle = (*(data->stack_a))->next->num;
	tail = (*(data->stack_a))->prev->num;
	if (head < middle && middle < tail)
		return (ft_strdup("")); //1 2 3
	if (head < middle && middle > tail)
		return (ft_strdup("sa\nra\n")); // 1 3 2
	if (head > middle && middle < tail && head < tail)
		return (ft_strdup("sa\n")); // 2 1 3
	if (head < middle && middle > tail)
		return (ft_strdup("rra\n")); // 2 3 1
	if (head > middle && middle < tail)
		return (ft_strdup("ra\n")); // 3 1 2
	if (head > middle && middle > tail)
		return (ft_strdup("sa\nrra\n")); // 3 2 1
}