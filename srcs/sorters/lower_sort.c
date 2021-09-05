/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:36:12 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/03 11:38:02 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_stack.h"
#include "sorters.h"

void	sort_2(t_stack *a)
{
	if (a->tab[0] > a->tab[1])
		sa(a, NULL);
}

void	sort_3(t_stack *a)
{
	if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[0] < a->tab[2])
		sa(a, NULL);
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
	{
		sa(a, NULL);
		rra(a, NULL);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[0] > a->tab[2])
		ra(a, NULL);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[0] < a->tab[2])
	{
		sa(a, NULL);
		ra(a, NULL);
	}
	else
		rra(a, NULL);
}

int	find_in_between_inf(t_stack stk, long val)
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
		if (stk.tab[i] < val && stk.tab[j] > val)
			return (stk.tab[j]);
	}
	return (stk.tab[0]);
}

void	sort_4_5(t_stack *a, t_stack *b)
{
	t_stack_mv	mv;

	pb(a, b);
	pb(a, b);
	sort_3(a);
	while (b->size)
	{
		mv = find_shortest_to_top(*a, find_in_between_inf(*a, b->tab[0]));
		if (mv.forward)
			while (mv.nbr--)
				ra(a, b);
		else
			while (mv.nbr--)
				rra(a, b);
		pa(a, b);
	}
	mv = find_shortest_to_top(*a, a->tab[find_lowest(a)]);
	if (mv.forward)
		while (mv.nbr--)
			ra(a, b);
	else
		while (mv.nbr--)
			rra(a, b);
	pa(a, b);
}
