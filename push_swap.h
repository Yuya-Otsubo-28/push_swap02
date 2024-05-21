/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/21 13:49:01 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define true 1
# define false 0

# define A 1
# define B -1

typedef int t_bool;
typedef int t_name;

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