/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:46:58 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/02 17:09:00 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	under_five_case(t_pslist *stack, int size, t_name name, t_list **res)
{
	if (size == 2)
		sort_2(stack, name, res);
	else if (size == 3)
		sort_3(stack, name, res);
	else if (size == 4)
		sort_4(stack, name, res);
	else if (size == 5)
		sort_5(stack, name, res);
	return ;
}

t_bool	is_sorted(t_pslist *stack)
{
	while (1)
	{
		if (stack->next->is_top)
			break ;
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static int	get_stack_size(t_pslist *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (1)
	{
		size++;
		if (stack->next->is_top)
			break ;
		stack = stack->next;
	}
	return (size);
}

static int	get_middle(t_pslist *stack)
{
	int	max;
	int	min;

	max = INT_MIN;
	min = INT_MAX;
	while (1)
	{
		if (stack->next->is_top)
			break ;
		if (stack->num > max)
			max = stack->num;
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return ((max - min) / 2);
}

static int	divide_half(t_pslist **main_stack, t_pslist **sub_stack, t_name name)
{
	int	middle;
	
	middle = get_middle(*main_stack);
	while (1)
	{
		if ((*main_stack)->next->is_top)
			break ;
		if ((*main_stack)->num < middle)
			push(main_stack, sub_stack, name * -1);
		else
			rotate(main_stack, name);
		*main_stack = (*main_stack)->next;
	}
	return (middle);
}

static int	recusive_sort(t_pslist **stack_a, t_pslist **stack_b, t_list **res, int pre_size)
{
	int	middle;
	int	b_size;
	int	pushed_size;
	int	i;
	int	j;

	if (!stack_b && is_sorted(stack_a))
		return (0);
	b_size = get_stack_size(*stack_b);
	if (b_size <= 5)
	{
		under_five_case(*stack_b, b_size, B, res);
		i = 0;
		while (i++ < b_size)
		{
			push(stack_b, stack_a, A);
			rotate(stack_a, A);
		}
		*stack_b = NULL;
		return (b_size);
	}
	recusive_sort(stack_a, stack_b, res, b_size);
	j = 0;
	while (pushed_size + j++ < pre_size)
		push(stack_a, stack_b, B);
	recusive_sort(stack_a, stack_b, res, j);
	return ;
}

void	sort(t_pslist **stack_a, t_list **res)
{
	int			a_size;
	t_pslist	*stack_b;

	a_size = get_stack_size(*stack_a);
	if (a_size <= 5)
	{
		under_five_case(*stack_a, a_size, A, res);
		return ;
	}
	stack_b = NULL;
	recusive_sort(stack_a, &stack_b, res, a_size);
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
// 	printf("\ttest: sort\n\n");
// 	sort(stack_a, &res);

// 	print_result(res);

// 	free(comp_res);
// 	free(ary_res);
// 	return (0);
// }