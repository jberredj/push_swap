/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:56:57 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/03 11:25:11 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/includes/libft.h"
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "sorters.h"
#include "insertion_sort.h"
#include <stdbool.h>
#include <stdint.h>

int	find_in_between(t_stack stk, long val)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < (int)stk.size)
	{
		j++;
		if (j >= (int)stk.size)
			j = 0;
		if (stk.tab[i] > val && stk.tab[j] < val)
			return (stk.tab[j]);
	}
	return (stk.tab[stk.size - 1]);
}

static t_dstk_mv	combined_two_mv(t_stack_mv mv_a, t_stack_mv mv_b)
{
	t_dstk_mv	new_mv;

	new_mv.type = 0;
	new_mv.comb = 0;
	new_mv.a_nbr = 0;
	new_mv.b_nbr = 0;
	if (mv_a.forward)
		new_mv.type += RA;
	else
		new_mv.type += RRA;
	if (mv_b.forward)
		new_mv.type += RB;
	else
		new_mv.type += RRB;
	new_mv.a_nbr = mv_a.nbr;
	new_mv.b_nbr = mv_b.nbr;
	return (new_mv);
}

t_dstk_mv	test_move(int index, t_stack *a, t_stack *b)
{
	long		value;
	int			low;
	int			high;
	t_stack_mv	mv_a;
	t_stack_mv	mv_b;

	value = a->tab[index];
	low = b->tab[find_lowest(b)];
	high = b->tab[find_biggest(b)];
	mv_a = find_shortest_to_top(*a, value);
	if (value > high || value < low)
		low = high;
	else if (value > low && value < high)
		low = find_in_between(*b, value);
	mv_b = find_shortest_to_top(*b, low);
	return (combined_two_mv(mv_a, mv_b));
}
