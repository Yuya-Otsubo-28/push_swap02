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
		tmp = pslist_new(input[i]);
		if (!tmp)
			return (NULL);
		pslist_addback(res, tmp);
	}
	return (res);
}