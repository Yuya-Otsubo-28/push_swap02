/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ary_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/02 15:38:39 by yuotsubo         ###   ########.fr       */
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
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	*arg_2_case(char *argv[], int *size)
{
	size_t	i;
	int		*res;
	char	**args;

	args = ft_split(argv[1], ' ');
	if (!args)
		return (NULL);
	*size = 0;
	while (args[*size])
		(*size)++;
	res = (int *)malloc(sizeof(int) * *size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (size_t)*size)
	{
		if (!is_valid_arg(args[i]))
			return (err_return(res));
		res[i] = ft_atoi(args[i]);
		i++;
	}
	if (is_duplicated(res, *size))
		return (err_return(res));
	return (res);
}

// 'len' is for counting length of int array.
// If input is a string, 'argc' shouldn't use as length of int array. (beacause 'argc' is always 2 then.)

int	*ary_init(int argc, char *argv[], int *len)
{
	size_t	i;
	int		*res;

	if (argc == 2)
		return (arg_2_case(argv, len));
	*len = argc - 1;
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
	if (is_duplicated(res, argc - 1))
		return (err_return(res));
	return (res);
}

/*	tests
- basic input OK
- input as a string OK
- duplicated input OK (NO Leaks, return NULL)
- outrange of int OK (NO Leaks, return NULL)
*/

// int	main(int argc, char *argv[])
// {
// 	int	*res;
// 	int	size;

// 	res = ary_init(argc, argv, &size);
// 	if (!res)
// 	{
// 		printf("NULL returned\n"); fflush(stdout);
// 		return (0);
// 	}
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d\n", res[i]); fflush(stdout);
// 	}
// 	printf("size: %d\n", size);
// 	free(res);
// 	return (0);
// }