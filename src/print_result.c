/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:38:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/14 09:48:58 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_bool	print_result(t_list *res)
{
	t_list	*node;

	node = res;
	while (1)
	{
		if (!node)
			return (FALSE);
		if (!ft_strncmp((char *)node->content, "end", 3))
			break ;
		node = node->next;
	}
	while (1)
	{
		if (!ft_strncmp((char *)res->content, "end", 3))
			return (TRUE);
		if (((char *)(res->content))[0])
			ft_putendl_fd(res->content, STDOUT_FILENO);
		res = res->next;
	}
}
