#include "libft.h"
#include "../push_swap.h"

t_pslist	*pslist_new(int n)
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

t_pslist	*pslist_addback(t_pslist **lst, t_pslist *new)
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