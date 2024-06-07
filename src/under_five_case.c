#include "push_swap.h"
#include "libft.h"

// void	__print_stack(t_pslist *stack);

static void	opt_sort_2(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	t_pslist *first;
	t_pslist *second;

	if (name == A)
	{
		sort_2(stack, name, res);
		return ;
	}
	first = *stack;
	second = (*stack)->next;
	if (first->num < second->num)
	{
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
	else
	{
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
}

static void	opt_sort_3(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	int	i;

	if (name == A)
	{
		sort_3(stack, name, res);
		return ;
	}
	if ((*stack)->num < (*stack)->next->num && (*stack)->next->num < (*stack)->prev->num)
	{
		i = 0;
		while (i++ < 3)
		{
			ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
			ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		}
	}
	else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > (*stack)->prev->num \
		&& (*stack)->num < (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
	else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < (*stack)->prev->num \
		&& (*stack)->num < (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
	else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > (*stack)->prev->num \
		&& (*stack)->num > (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(swap(stack, name)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
	else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < (*stack)->prev->num \
		&& (*stack)->num > (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
	else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num > (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
		ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	}
}

static void	opt_sort_4(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	int			most_small;
	int			next_small;

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
	opt_sort_2(stack, sub_stack, name, res);
}

static void	opt_sort_5(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	int			most_small;
	int			next_small;

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
	opt_sort_3(stack, sub_stack, name, res);
}

void	under_five_case(t_pslist **stack, t_pslist **stack2, int size, t_name name, t_list **res)
{
	// if (is_sorted(*stack))
	// 	return ;
	if (size == 2)
		opt_sort_2(stack, stack2, name, res);
	else if (size == 3)
		opt_sort_3(stack, stack2, name, res);
	else if (size == 4)
		opt_sort_4(stack, stack2, name, res);
	else if (size == 5)
		opt_sort_5(stack, stack2, name, res);
	return ;
}