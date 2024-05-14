/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:38:48 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/14 13:44:38 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

// int	main(void)
// {
// 	int	input[] = {123, INT_MAX, INT_MIN, -3};
// 	int	size = 4;
// 	int	*res;

// 	res = compress(input, size);
// 	for (int i = 0; i < size; i++)
// 		printf("%d\n", res[i]);
// 	free(res);
// 	return (0);
// }