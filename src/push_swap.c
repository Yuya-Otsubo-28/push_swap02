/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:10:05 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/15 15:43:11 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	err_return(int *input, t_pslist *stack_a)
{
	if (input)
		input = map_and_free(NULL, input);
	if (stack_a)
		stack_a = map_and_free(NULL, stack_a);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int			*input;
	t_pslist	**stack_a;
	char		*res;

	if (argc < 2)
		return (err_return(NULL, NULL));
	input = ary_init(argc, argv);
	if (!input)
		return (err_return(NULL, NULL));
	input = map_and_free(compress(input, argc - 1), input);
	if (!input)
		return (err_return(NULL, NULL));
	stack_a = stack_init(input, argc - 1);
	if (!stack_a)
		return (err_return(input, NULL));
	res = solve(stack_a);
	if (!res)
		return (err_return(input, stack_a));
	res = map_and_free(optimize(res), res);
	if (!res)
		return (err_return(input, stack_a));
	print_result(res);
	return (EXIT_SUCCESS);
}