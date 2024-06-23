/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:10:05 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/23 18:39:05 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_pslist	*free_stack(t_pslist *stack)
{
	int			stack_size;
	t_pslist	*next;
	int			i;

	stack_size = get_stack_size(stack);
	i = 0;
	while (i++ < stack_size)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	return (NULL);
}

static void	free_list(t_list *res)
{
	t_list	*tmp;

	while (res)
	{
		tmp = res->next;
		free(res);
		res = tmp;
	}
}

static void	free_all(int *input, t_pslist **stack_a, t_list *res)
{
	if (input)
		free(input);
	if (stack_a && *stack_a)
		free_stack(*stack_a);
	if (stack_a)
		free(stack_a);
	if (res)
		free_list(res);
}

static int	err_return(int *input, t_pslist **stack_a, t_list *res)
{
	free_all(input, stack_a, res);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int			*input;
	int			input_len;
	t_pslist	**stack_a;
	t_list		*res;

	res = NULL;
	input = ary_init(argc, argv, &input_len);
	if (!input)
		return (err_return(NULL, NULL, NULL));
	input = map_and_free(compress(input, input_len), input);
	if (!input)
		return (err_return(NULL, NULL, NULL));
	stack_a = stack_init(input, input_len);
	if (!stack_a)
		return (err_return(input, NULL, NULL));
	sort(stack_a, &res);
	if (!res)
		return (err_return(input, stack_a, NULL));
	if (!print_result(res))
		return (err_return(input, stack_a, res));
	free_all(input, stack_a, res);
	return (EXIT_SUCCESS);
}
