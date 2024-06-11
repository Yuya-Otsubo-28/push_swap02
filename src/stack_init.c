/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:16:40 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/11 19:21:25 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

t_pslist	**stack_init(int *input, int size)
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

// int	main(int argc, char *argv[])
// {
// 	int	*ary_res;
// 	int	*comp_res;
// 	t_pslist **stack_a;
// 	int	size;

// 	ary_res = ary_init(argc, argv, &size);
// 	printf("***********************\n");
// 	printf("\ttest: ary_init\n\n");
// 	if (!ary_res)
// 	{
// 		printf("NULL returned\n"); fflush(stdout);
// 		return (0);
// 	}
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("ary_res[%d]: %d\n", i, ary_res[i]); fflush(stdout);
// 	}
// 	printf("size: %d\n", size);

// 	printf("***********************\n\n");
// 	printf("\ttest: compress\n\n");
// 	comp_res = compress(ary_res, size);
// 	for (int i = 0; i < size; i++)
// 		printf("comp_res[%d]: %d\n", i, comp_res[i]);

// 	printf("***********************\n\n");
// 	printf("\ttest: stack_init\n\n");
// 	stack_a = stack_init(comp_res, size);
// 	for (t_pslist *node = *stack_a; ; node = node->next)
// 	{
// 		printf("list content: %d\n", node->num);
// 		if (node->next->is_top)
// 			break ;
// 		printf("< next >\n");
// 	}
// 	printf("\n");
// 	for (t_pslist *node = *stack_a; ; node = node->prev)
// 	{
// 		printf("list content: %d\n", node->num);
// 		if (node->prev->is_top)
// 			break ;
// 		printf("< prev >\n");
// 	}

// 	free(comp_res);
// 	free(ary_res);
// 	return (0);
// }
