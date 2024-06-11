/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:26:04 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/11 19:28:14 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sort_1_2_3(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}

void	sort_1_2(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}

void	sort_2_1(t_pslist **stack, t_pslist **sub_stack, \
		t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}
