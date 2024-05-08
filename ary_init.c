/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ary_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/08 21:30:10 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	*err_return(int *res)
{
	if (res)
		free(res);
	return (NULL);
}

static t_bool	is_int_range(int res, int flag, char c)
{
	if (res * flag > INT_MAX / 10 \
	|| (res * flag == INT_MAX / 10 && c - '0' > INT_MAX % 10))
		return (false);
	if (res * flag < INT_MIN / 10 \
	|| (res * flag == INT_MIN / 10 && -(c - '0') < INT_MIN % 10))
		return (false);
	return (true);
}

static t_bool	is_valid_arg(char *arg)
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
			return (false);
		if (!is_int_range(res, flag, arg[i]))
			return (false);
		res *= 10;
		res += arg[i++] - '0';
	}
	return (true);
}

int	*ary_init(int argc, char *argv[])
{
	size_t	i;
	int		*res;

	res = (int *)malloc(sizeof(int) * argc - 1);
	if (!res)
		return (NULL);
	i = 1;
	while (i < (size_t)argc)
	{
		if (!is_valid_arg(argv[i]))
			return (err_return(res));
		res[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (res);
}

// int	main(void)
// {
// 	int	*res;
// 	char *argv[] = {"this is the program name", "123", "134", "621", "431"};

// 	res = ary_init(5, argv);
// 	if (!res)
// 	{
// 		printf("NULL returned\n"); fflush(stdout);
// 		return (0);
// 	}
// 	for (int i = 0; i < 4; i++)
// 	{
// 		printf("%d\n", res[i]); fflush(stdout);
// 	}
// 	free(res);
// 	return (0);
// }