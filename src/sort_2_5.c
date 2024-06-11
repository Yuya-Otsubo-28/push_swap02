/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/11 19:35:07 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sort_2(t_pslist **stack, t_name name, t_list **res)
{
	int	head;
	int	tail;

	head = (*stack)->num;
	tail = (*stack)->next->num;
	if (head > tail)
		ft_lstadd_back(res, ft_lstnew(swap(stack, name)));
	else
		ft_lstadd_back(res, ft_lstnew(""));
}

static void	sub_sort_3(t_pslist **stack, t_name name, t_list **res)
{
	if ((*stack)->num < (*stack)->next->num && \
			(*stack)->next->num > (*stack)->prev->num \
		&& (*stack)->num > (*stack)->prev->num)
		ft_lstadd_back(res, ft_lstnew(rev_rotate(stack, name)));
	if ((*stack)->num > (*stack)->next->num && \
			(*stack)->next->num < (*stack)->prev->num \
		&& (*stack)->num > (*stack)->prev->num)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	if ((*stack)->num > (*stack)->next->num && \
			(*stack)->next->num > (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(swap(stack, name)));
		ft_lstadd_back(res, ft_lstnew(rev_rotate(stack, name)));
	}
}

void	sort_3(t_pslist **stack, t_name name, t_list **res)
{
	if ((*stack)->num < (*stack)->next->num && \
			(*stack)->next->num < (*stack)->prev->num)
		ft_lstadd_back(res, ft_lstnew(""));
	if ((*stack)->num < (*stack)->next->num && \
			(*stack)->next->num > (*stack)->prev->num \
		&& (*stack)->num < (*stack)->prev->num)
	{
		ft_lstadd_back(res, ft_lstnew(swap(stack, name)));
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	}
	if ((*stack)->num > (*stack)->next->num && \
			(*stack)->next->num < (*stack)->prev->num \
		&& (*stack)->num < (*stack)->prev->num)
		ft_lstadd_back(res, ft_lstnew(swap(stack, name)));
	sub_sort_3(stack, name, res);
}

void	sort_4(t_pslist **stack, t_name name, t_list **res)
{
	t_pslist	*sub_stack;
	int			most_small;
	int			next_small;

	if (is_sorted(*stack))
		return ;
	sub_stack = NULL;
	get_small_nums(*stack, &most_small, &next_small, 4);
	while ((*stack)->num != most_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, &sub_stack, name * -1)));
	while ((*stack)->num != next_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, &sub_stack, name * -1)));
	sort_2(stack, name, res);
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, stack, name)));
}

void	sort_5(t_pslist **stack, t_name name, t_list **res)
{
	t_pslist	*sub_stack;
	int			most_small;
	int			next_small;

	if (is_sorted(*stack))
		return ;
	sub_stack = NULL;
	get_small_nums(*stack, &most_small, &next_small, 5);
	while ((*stack)->num != most_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, &sub_stack, name * -1)));
	while ((*stack)->num != next_small)
		ft_lstadd_back(res, ft_lstnew(rotate(stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(stack, &sub_stack, name * -1)));
	sort_3(stack, name, res);
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, stack, name)));
	ft_lstadd_back(res, ft_lstnew(push(&sub_stack, stack, name)));
}

// int	main(int argc, char *argv[])
// {
// 	int	*ary_res;
// 	int	*comp_res;
// 	t_pslist **stack_a;
// 	t_list *res;
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

// 	printf("***********************\n\n");
// 	printf("\ttest: under_five_case\n\n");
// 	res = NULL;
// 	under_five_case(*stack_a, size, A, &res);
// 	print_result(res);

// 	free(comp_res);
// 	free(ary_res);
// 	return (0);
// }
