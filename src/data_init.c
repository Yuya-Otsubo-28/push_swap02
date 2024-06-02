/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:16:40 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/22 15:16:40 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_pslist	*pslist_new(int n)
{
	t_pslist	*res;

	res = (t_pslist *)malloc(sizeof(t_pslist));
	if (!res)
		return (NULL);
	res->prev = NULL;
	res->next = NULL;
	res->num = n;
	res->is_top = false;
	return (res);
}

static t_pslist	*pslist_addback(t_pslist **lst, t_pslist *new)
{
	t_pslist	*head;

	if (!lst)
		return (NULL);
	if (!*lst)
	{
		new->is_top = true;
		*lst = new;
		return (*lst);
	}
	head = *lst;
	if (!head->prev)
	{
		head->prev = new;
		head->next = new;
		new->prev = head;
		new->next = head;
		return (head);
	}
	head->prev->next = new;
	new->prev = head->prev;
	head->prev = new;
	new->next = head;
	return (head);
}

static t_pslist	**stack_init(int *input, int size)
{
	t_pslist	**res;
	int			i;
	t_pslist	*tmp;

	res = (t_pslist **)malloc(sizeof(t_pslist *) * size);
	if (!res)
		return (NULL);
	*res = NULL;
	i = 0;
	while (i < size)
	{
		tmp = pslist_new(input[i++]);
		if (!tmp)
			return (NULL);
		*res = pslist_addback(res, tmp);
		if (!(*res))
			return (NULL);
	}
	return (res);
}

t_data	*data_init(int *input, int size)
{
	t_data	*res;

	res = (t_data *)malloc(sizeof(t_data));
	if (!res)
		return (NULL);
	res->stack_a = stack_init(input, size);
	if (!res->stack_a)
	{
		free(res);
		return (NULL);
	}
	res->stack_b = NULL;
	res->total_size = size;
	res->a_size = size;
	res->b_size = 0;
	return (res);
}

// int	main(void)
// {
// 	int			input[] = {12, 234, 45, 56};
// 	int			size = 4;
// 	t_pslist	**res;
// 	t_bool		flag = false;

// 	res = stack_init(input, size);
// 	while (1)
// 	{
// 		if ((*res)->is_top && flag)
// 			break ;
// 		if ((*res)->is_top)
// 			flag = true;
// 		printf("res: %d\n", (*res)->num);
// 		*res = (*res)->prev;
// 	}
// 	return (0);
// }