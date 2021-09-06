/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:53:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 11:41:40 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
#include "sorters.h"

void	biggest_is_faster(t_stack *a, t_stack *b, t_stack_mv mv)
{
	if (b->size > 1)
	{
		if (mv.forward)
			while (mv.nbr--)
				rb(a, b, true);
		else
			while (mv.nbr--)
				rrb(a, b, true);
	}
	pa(a, b, true);
}

void	lowest_is_faster(t_stack *a, t_stack *b, t_stack_mv mv)
{
	if (b->size > 1)
	{
		if (mv.forward)
			while (mv.nbr--)
				rb(a, b, true);
		else
			while (mv.nbr--)
				rrb(a, b, true);
	}
	pa(a, b, true);
	ra(a, b, true);
}

void	sort_b(t_stack *a, t_stack *b)
{
	size_t		index;
	t_stack_mv	mv_b;
	t_stack_mv	mv_l;

	while (b->size)
	{
		index = find_biggest(b);
		mv_b = find_shortest_to_top(*b, b->tab[index]);
		index = find_lowest(b);
		mv_l = find_shortest_to_top(*b, b->tab[index]);
		if (mv_b.nbr < mv_l.nbr)
			biggest_is_faster(a, b, mv_b);
		else
			lowest_is_faster(a, b, mv_l);
	}
}
