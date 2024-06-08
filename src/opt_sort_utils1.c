#include "push_swap.h"
#include "libft.h"

void	sort_1_3_2(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}

void	sort_2_1_3(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}

void	sort_2_3_1(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(swap(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}

void	sort_3_1_2(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}

void	sort_3_2_1(t_pslist **stack, t_pslist **sub_stack, t_name name, t_list **res)
{
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(push(stack, sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
	ft_lstadd_back(res, ft_lstnew(rotate(sub_stack, name * -1)));
}
