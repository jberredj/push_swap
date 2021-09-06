/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:36:12 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 12:18:24 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "structs/t_stack.h"
#include "sorters.h"

void	sort_2(t_stack *a)
{
	if (a->tab[0] > a->tab[1])
		sa(a, NULL, true);
}

void	sort_3(t_stack *a)
{
	if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[0] < a->tab[2])
		sa(a, NULL, true);
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
	{
		sa(a, NULL, true);
		rra(a, NULL, true);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[0] > a->tab[2])
		ra(a, NULL, true);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[0] < a->tab[2])
	{
		sa(a, NULL, true);
		ra(a, NULL, true);
	}
	else
		rra(a, NULL, true);
}

int	test_low_high(t_stack stk, int val)
{
	int	low;
	int	high;

	low = stk.tab[find_lowest(&stk)];
	high = stk.tab[find_biggest(&stk)];
	if (val < low || val > high)
		return (low);
	return (stk.tab[0]);
}

int	find_in_between_inf(t_stack stk, long val)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < (int)stk.size - 1)
	{
		j++;
		if (j >= (int)stk.size)
			j = 0;
		if (stk.tab[i] < val && stk.tab[j] > val)
			return (stk.tab[j]);
	}
	return (test_low_high(stk, val));
}

void	sort_4_5(t_stack *a, t_stack *b)
{
	t_stack_mv	mv;

	pb(a, b, true);
	pb(a, b, true);
	sort_3(a);
	while (b->size)
	{
		mv = find_shortest_to_top(*a, find_in_between_inf(*a, b->tab[0]));
		if (mv.forward)
			while (mv.nbr--)
				ra(a, b, true);
		else
			while (mv.nbr--)
				rra(a, b, true);
		pa(a, b, true);
	}
	mv = find_shortest_to_top(*a, a->tab[find_lowest(a)]);
	if (mv.forward)
		while (mv.nbr--)
			ra(a, b, true);
	else
		while (mv.nbr--)
			rra(a, b, true);
	pa(a, b, true);
}
