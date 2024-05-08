/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:10:05 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/08 20:16:04 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err_return(void)
{
	ft_putstr_fd();
	return (1);
}

int	main(int argc, char *argv[])
{
	int			*input;
	t_pslist	*stack_a;

	if (argc < 2)
		return (err_return());
	input = init(argc, argv);
	if (!input)
		return (err_return());
	
}