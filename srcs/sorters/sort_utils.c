/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:06:28 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/03 11:24:51 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"

int	roundup_divide(int nbr, int div)
{
	double	d_res;
	int		i_res;
	double	diff;

	i_res = nbr / div;
	d_res = (double)nbr / (double)div;
	diff = d_res - (double)i_res;
	if (diff != 0.0)
		return (i_res + 1);
	return (i_res);
}

int	find_in_stack(t_stack s, long val)
{
	int	i;

	i = -1;
	while (++i < (int)s.size)
	{
		if (s.tab[i] == val)
			return (i);
	}
	return (-1);
}

t_stack_mv	find_shortest_to_top(t_stack s, long val)
{
	int			val_pos;

	val_pos = find_in_stack(s, val);
	if (val_pos < roundup_divide(s.size, 2))
		return ((t_stack_mv){.nbr = val_pos, .forward = true});
	return ((t_stack_mv){.nbr = s.size - val_pos, .forward = false});
}

size_t	find_biggest(t_stack *stk)
{
	size_t	i;
	long	biggest;
	size_t	biggest_index;

	i = -1;
	biggest = stk->tab[0];
	biggest_index = 0;
	while (++i < stk->size)
	{
		if (stk->tab[i] > biggest)
		{
			biggest_index = i;
			biggest = stk->tab[i];
		}
	}
	return (biggest_index);
}

size_t	find_lowest(t_stack *stk)
{
	size_t	i;
	long	lowest;
	size_t	lowest_index;

	i = -1;
	lowest = stk->tab[0];
	lowest_index = 0;
	while (++i < stk->size)
	{
		if (stk->tab[i] < lowest)
		{
			lowest_index = i;
			lowest = stk->tab[i];
		}
	}
	return (lowest_index);
}
