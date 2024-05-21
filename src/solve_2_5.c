/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/21 13:43:31 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

char	*solve_2(t_pslist *stack)
{
	int	head;
	int tail;

	head = stack->num;
	tail = stack->next->num;
	if (head > tail)
		return (ft_strdup("ra\n"));
	return (ft_strdup(""));
}

// ft_strdup()をそのままreturnしてるから、連結させる時のNULLチェクが必要
// cmdを作って, map_and_free(ft_strjoin(res, swap(&stack, name)), res)などとする.


char	*solve_3(t_pslist *stack)
{
	int	head;
	int	middle;
	int tail;

	head = stack->num;
	middle = stack->next->num;
	tail = stack->prev->num;
	if (head < middle && middle < tail)
		return (ft_strdup("")); //1 2 3
	if (head < middle && middle > tail && head < tail)
		return (ft_strdup("sa\nra\n")); // 1 3 2
	if (head > middle && middle < tail && head < tail)
		return (ft_strdup("sa\n")); // 2 1 3
	if (head < middle && middle > tail && head > tail)
		return (ft_strdup("rra\n")); // 2 3 1
	if (head > middle && middle < tail && head > tail)
		return (ft_strdup("ra\n")); // 3 1 2
	if (head > middle && middle > tail)
		return (ft_strdup("sa\nrra\n")); // 3 2 1
}

static t_bool	reverse_or_not(t_pslist *current, int n, int size)
{
	int	count;

	count = 0;
	while (current->num != n)
	{
		current = current->next;
		count++;
	}
	if (count > size / 2)
		return (true);
	return (false);
}

char	*solve_4(t_pslist *stack)
{
	t_bool		flag_zero;
	t_bool		flag_one;
	char		*res;

	flag_zero = reverse_or_not(stack, )
}