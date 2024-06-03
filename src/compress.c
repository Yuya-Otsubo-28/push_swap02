/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:38:48 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/06/03 16:38:03 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*compress(int *input, int size)
{
	int	*res;
	long long	prev_min;
	int	min_index;
	long long	min;
	int	i;
	int	j;

	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	prev_min = LLONG_MIN;
	i = 0;
	while (i < size)
	{
		min = LLONG_MAX;
		j = 0;
		while (j < size)
		{
			if ((long long)input[j] > prev_min && (long long)input[j] <= min)
			{
				min_index = j;
				min = input[min_index];
			}
			j++;
		}
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
