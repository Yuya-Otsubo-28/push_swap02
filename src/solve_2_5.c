/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/22 14:44:10 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

void	solve_2(t_pslist *stack, t_name name, t_list **res)
{
	int		head;
	int 	tail;

	head = stack->num;
	tail = stack->next->num;
	if (head > tail)
		ft_lstadd_back(res, ft_lstnew(swap(&stack, name)));
	else
		ft_lstadd_back(res, ft_lstnew(ft_strdup("")));
}

// ft_strdup()をそのままreturnしてるから、連結させる時のNULLチェクが必要
// cmdを作って, map_and_free(ft_strjoin(res, swap(&stack, name)), res)などとする.


void	solve_3(t_pslist *stack, t_name name, t_list **res)
{
	if (stack->num < stack->next->num && stack->next->num < stack->prev->num)
		ft_lstadd_back(res, ft_lstnew(ft_strdup("")));
	if (stack->num < stack->next->num && stack->next->num > stack->prev->num \
		&& stack->num < stack->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(swap(&stack, name)));
		ft_lstadd_back(res, ft_lstnew(rotate(&stack, name)));
	} // 1 3 2
	if (stack->num > stack->next->num && stack->next->num < stack->prev->num \
		&& stack->num < stack->prev->num)
		ft_lstadd_back(res, ft_lstnew(swap(&stack, name)));
	if (stack->num < stack->next->num && stack->next->num > stack->prev->num \
		&& stack->num > stack->prev->num)
		ft_lstadd_back(res, ft_lstnew(rev_rotate(&stack, name)));
	if (stack->num > stack->next->num && stack->next->num < stack->prev->num \
		&& stack->num > stack->prev->num)
		ft_lstadd_back(res, ft_lstnew(rotate(&stack, name)));
	if (stack->num > stack->next->num && stack->next->num > stack->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(swap(&stack, name)));
		ft_lstadd_back(res, ft_lstnew(rev_rotate(&stack, name)));
	} // 3 2 1
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

char	*solve_4(t_pslist *stack, t_name name, t_list **res)
{
	t_pslist	*sub_stack;

	sub_stack = NULL;
	if (reverse_or_not(stack, 0, 4))
		while (stack->num != 0)
			ft_lstadd_back(res, ft_lstnew(rev_rotate(&stack, name)));
	else
		while (stack->num != 0)
			ft_lstadd_back(res, ft_lstnew(rotate(&stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&stack, &sub_stack, name * -1)));
	if (reverse_or_not(stack, 1, 3))
		while (stack->num != 1)
			ft_lstadd_back(res, ft_lstnew(rev_rotate(&stack, name)));
	else
		while (stack->num != 1)
			ft_lstadd_back(res, ft_lstnew(rotate(&stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&stack, &sub_stack, name * -1)));
	solve_2(stack, name, res);
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, &stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, &stack, name)));
}

char	*solve_5(t_pslist *stack, t_name name, t_list **res)
{
	t_pslist	*sub_stack;

	sub_stack = NULL;
	if (reverse_or_not(stack, 0, 5))
		while (stack->num != 0)
			ft_lstadd_back(res, ft_lstnew(rev_rotate(&stack, name)));
	else
		while (stack->num != 0)
			ft_lstadd_back(res, ft_lstnew(rotate(&stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&stack, &sub_stack, name * -1)));
	if (reverse_or_not(stack, 1, 4))
		while (stack->num != 1)
			ft_lstadd_back(res, ft_lstnew(rev_rotate(&stack, name)));
	else
		while (stack->num != 1)
			ft_lstadd_back(res, ft_lstnew(rotate(&stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&stack, &sub_stack, name * -1)));
	solve_3(stack, name, res);
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, &stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, &stack, name)));
}