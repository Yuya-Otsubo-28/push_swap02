/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ary_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/11 18:15:10 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_bool	is_int_range(int res, int flag, char c)
{
	if (res * flag > INT_MAX / 10 \
	|| (res * flag == INT_MAX / 10 && c - '0' > INT_MAX % 10))
		return (FALSE);
	if (res * flag < INT_MIN / 10 \
	|| (res * flag == INT_MIN / 10 && -(c - '0') < INT_MIN % 10))
		return (FALSE);
	return (TRUE);
}

t_bool	is_valid_arg(char *arg)
{
	long long	res;
	int			flag;
	size_t		i;

	while (ft_isspace(*arg))
		arg++;
	flag = 1;
	if (*arg == '+' || *arg == '-')
		if (*arg++ == '-')
			flag *= -1;
	i = 0;
	res = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		if (!is_int_range(res, flag, arg[i]))
			return (FALSE);
		res *= 10;
		res += arg[i++] - '0';
	}
	return (TRUE);
}

t_bool	is_duplicated(int *ary, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ary[i] == ary[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
