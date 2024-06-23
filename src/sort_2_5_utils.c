/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_5_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:00:06 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/23 21:00:06 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_bool	is_use_rotate(t_pslist *stack, int n)
{
	int	size;
	int	i;

	size = get_stack_size(stack);
	i = 0;
	while (i < size / 2)
	{
		if (stack->num == n)
			return (TRUE);
		stack = stack->next;
		i++;
	}
	return (FALSE);
}

void	rotate_untill_n(t_pslist **stack, t_name name, t_list **res, int n)
{
	t_bool	use_rotate;

	if ((*stack)->num == n)
		return ;
	use_rotate = is_use_rotate(*stack, n);
	while (1)
	{
		if (use_rotate == TRUE)
			ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
		else
			ft_lstadd_back(res, ft_lstnew(rev_rotate(stack, name)));
		if ((*stack)->num == n)
			break ;
	}
}
