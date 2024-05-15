/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/15 16:50:23 by yuotsubo         ###   ########.fr       */
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

typedef	struct s_data {
	int			total_size;
	int			a_size;
	int			b_size;
	t_pslist	**stack_a;
	t_pslist	**stack_b;
} t_data ;

#endif