#include "push_swap.h"
#include "libft.h"

static void	opt_sort_5(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	int			most_small;
	int			next_small;

	if (is_sorted(*stack))
		return ;
	if (name == A)
	{
		sort_5(stack, name, res);
		return ;
	}
	get_small_nums(*stack, &most_small, &next_small, 5);
	while ((*stack)->num != most_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	while ((*stack)->num != next_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	sort_3(stack, name, res);
}

static void	opt_sort_4(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	int			most_small;
	int			next_small;

	if (is_sorted(*stack))
		return ;
	if (name == A)
	{
		sort_4(stack, name, res);
		return ;
	}
	get_small_nums(*stack, &most_small, &next_small, 4);
	while ((*stack)->num != most_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	while ((*stack)->num != next_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	sort_2(stack, name, res);
}

void	under_five_case(t_pslist **stack, t_pslist **stack2, int size, t_name name, t_list **res)
{
	if (is_sorted(*stack))
		return ;
	if (size == 2)
		sort_2(stack, name, res);
	else if (size == 3)
		sort_3(stack, name, res);
	else if (size == 4)
		opt_sort_4(stack, stack2, name, res);
	else if (size == 5)
		opt_sort_5(stack, stack2, name, res);
	return ;
}