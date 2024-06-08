/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:38:48 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/08 14:04:33 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	search_min_index(int *input, int size, long long prev_min)
{
	int			i;
	int			min_index;
	long long	min;

	min = LLONG_MAX;
	i = 0;
	while (i < size)
	{
		if ((long long)input[i] > prev_min && (long long)input[i] <= min)
		{
			min_index = i;
			min = input[min_index];
		}
		i++;
	}
	return (min_index);
}

int	*compress(int *input, int size)
{
	int			*res;
	long long	prev_min;
	int			min_index;
	int			i;

	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	prev_min = LLONG_MIN;
	i = 0;
	while (i < size)
	{
		min_index = search_min_index(input, size, prev_min);
		res[min_index] = i++;
		prev_min = input[min_index];
	}
	return (res);
}

// int	main(int argc, char *argv[])
// {
// 	int	*ary_res;
// 	int	*comp_res;
// 	int	size;

// 	ary_res = ary_init(argc, argv, &size);
// 	printf("***********************\n");
// 	printf("\ttest: ary_init\n\n");
// 	if (!ary_res)
// 	{
// 		printf("NULL returned\n"); fflush(stdout);
// 		return (0);
// 	}
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("ary_res[%d]: %d\n", i, ary_res[i]); fflush(stdout);
// 	}
// 	printf("size: %d\n", size);
// 	printf("***********************\n\n");
// 	printf("\ttest: compress\n\n");
// 	comp_res = compress(ary_res, size);
// 	for (int i = 0; i < size; i++)
// 		printf("comp_res[%d]: %d\n", i, comp_res[i]);
// 	printf("***********************\n");
// 	free(comp_res);
// 	free(ary_res);
// 	return (0);
// }
