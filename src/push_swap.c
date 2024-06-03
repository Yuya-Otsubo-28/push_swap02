/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:10:05 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/03 16:39:15 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pslist *free_stack(t_pslist *stack_a)
{
	t_pslist	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = NULL;
		stack_a = tmp;
	}
	return (NULL);
}

static int	err_return(int *input, t_pslist *stack_a)
{
	if (input)
		input = map_and_free(NULL, input);
	if (stack_a)
		stack_a = free_stack(stack_a);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int			*input;
	int			*input_len;
	t_pslist	*stack_a;
	t_list		*res;

	if (argc < 2)
		return (err_return(NULL, NULL));
	input = ary_init(argc, argv, &input_len);
	if (!input)
		return (err_return(NULL, NULL));
	input = map_and_free(compress(input, input_len), input);
	if (!input)
		return (err_return(NULL, NULL));
	stack_a = stack_init(input, input_len);
	if (!stack_a)
		return (err_return(input, NULL));
	sort(stack_a, &res);
	if (!res)
		return (err_return(input, stack_a));
	// optimize(&res);
	// optimize()内で、res listにNULLなどのエラーを見つけたらfree and NULL
	// if (!res)
		// return (err_return(input, stack_a));
	print_result(res);
	return (EXIT_SUCCESS);
}