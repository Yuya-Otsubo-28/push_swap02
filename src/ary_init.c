/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ary_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/08 03:35:10 by yotsubo          ###   ########.fr       */
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

static void	free_all(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
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
	{
		free_all(args);
		return (NULL);
	}
	i = 0;
	while (i < (size_t)*size)
	{
		if (!is_valid_arg(args[i]))
		{
			free_all(args);
			return (err_return(res));
		}
		res[i] = ft_atoi(args[i]);
		i++;
	}
	if (is_duplicated(res, *size))
		return (err_return(res));
	free_all(args);
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
