/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:10:05 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/22 15:11:52 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_data *free_data(t_data *data)
{
	int			i;
	int			j;
	t_pslist	*tmp;

	i = 0;
	while (i++ < data->a_size)
	{
		if (i != data->a_size)
			tmp = (*(data->stack_a))->next;
		free(*(data->stack_a));
		(*(data->stack_a)) = tmp;
	}
	j = 0;
	while (j++ < data->b_size)
	{
		if (j != data->b_size)
			tmp = (*(data->stack_b))->next;
		free(*(data->stack_b));
		(*(data->stack_b)) = tmp;
	}
	return (NULL);
}

static int	err_return(int *input, t_data *data)
{
	if (input)
		input = map_and_free(NULL, input);
	if (data)
		data = free_data(data);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int			*input;
	t_data		*data;
	t_list		*res;

	if (argc < 2)
		return (err_return(NULL, NULL));
	input = ary_init(argc, argv);
	if (!input)
		return (err_return(NULL, NULL));
	input = map_and_free(compress(input, argc - 1), input);
	if (!input)
		return (err_return(NULL, NULL));
	data = data_init(input, argc - 1);
	if (!data)
		return (err_return(input, NULL));
	solve(data, &res);
	if (!res)
		return (err_return(input, data));
	optimize(&res);
	// optimize()内で、res listにNULLなどのエラーを見つけたらfree and NULL
	if (!res)
		return (err_return(input, data));
	print_result(res);
	return (EXIT_SUCCESS);
}