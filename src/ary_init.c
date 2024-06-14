/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ary_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:38:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/14 10:13:49 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	free_all(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	*err_return(int *res, char **args)
{
	if (res)
		free(res);
	if (args)
		free_all(args);
	return (NULL);
}

static int	*arg_2_case(char *argv[], int *size)
{
	int		i;
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
		return (err_return(NULL, args));
	i = -1;
	while (++i < *size)
	{
		if (!is_valid_arg(args[i]))
			return (err_return(res, args));
		res[i] = ft_atoi(args[i]);
	}
	if (is_duplicated(res, *size))
		return (err_return(res, args));
	free_all(args);
	return (res);
}

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
			return (err_return(res, NULL));
		res[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (is_duplicated(res, argc - 1))
		return (err_return(res, NULL));
	return (res);
}

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
