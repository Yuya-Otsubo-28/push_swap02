/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/21 20:18:01 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

char	*solve_2(t_pslist *stack, t_name name)
{
	int		head;
	int 	tail;
	char	*res;

	head = stack->num;
	tail = stack->next->num;
	if (head > tail)
		return (rotate(&stack, name));
	return (ft_strdup(""));
}

// ft_strdup()をそのままreturnしてるから、連結させる時のNULLチェクが必要
// cmdを作って, map_and_free(ft_strjoin(res, swap(&stack, name)), res)などとする.


char	*solve_3(t_pslist *stack, t_name name)
{
	char	*res;

	if (stack->num < stack->next->num && stack->next->num < stack->prev->num)
		res = ft_strdup(""); //1 2 3
	if (stack->num < stack->next->num && stack->next->num > stack->prev->num \
		&& stack->num < stack->prev->num)
	{
		res = swap(&stack, name);
		res = map_and_free(rotate(&stack, name), res);
	} // 1 3 2
	if (stack->num > stack->next->num && stack->next->num < stack->prev->num \
		&& stack->num < stack->prev->num)
		res = swap(&stack, name); // 2 1 3
	if (stack->num < stack->next->num && stack->next->num > stack->prev->num \
		&& stack->num > stack->prev->num)
		res = rev_rotate(&stack, name); // 2 3 1
	if (stack->num > stack->next->num && stack->next->num < stack->prev->num \
		&& stack->num > stack->prev->num)
		res = rotate(&stack, name); // 3 1 2
	if (stack->num > stack->next->num && stack->next->num > stack->prev->num)
	{
		res = swap(&stack, name);
		res = map_and_free(rev_rotate(&stack, name), res);
	} // 3 2 1
	return (res);
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

char	*solve_4(t_pslist *stack, t_name name)
{
	t_bool		flag_zero;
	t_bool		flag_one;
	char		*res;

	flag_zero = reverse_or_not(stack, )
}