/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:38:48 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/08 21:41:23 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	*compress(int *input, int size)
{
	int	*res;

	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	
}