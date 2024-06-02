/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:38:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/02 17:03:08 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_result(t_list *res)
{
	t_list *node;

	node = res;
	while (node)
	{
		if (((char *)(node->content))[0])
			ft_putendl_fd(node->content, STDOUT_FILENO);
		node = node->next;
	}
}