/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/08 21:15:09 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define true 1
# define false 0

typedef int t_bool;

typedef struct s_pslist {
	int				num;
	t_bool			is_top;
	struct s_pslist	*next;
	struct s_pslist	*prev;
} t_pslist ;

#endif