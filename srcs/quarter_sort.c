/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:58:27 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/25 12:12:13 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
#include "sorters.h"

void	first_quarter(t_stack *a, t_stack *b, t_med_qrt stats)
{
	size_t		i;
	t_stack_mv	next_mv;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] <= stats.frt_qrt)
		{
			next_mv = find_shortest_to_top(*a, a->tab[i]);
			if (next_mv.forward)
				while (next_mv.nbr--)
					ra(a);
			else
				while (next_mv.nbr--)
					rra(a);
			pb(a, b);
			i = -1;
		}
	}
}

void	second_quarter(t_stack *a, t_stack *b, t_med_qrt stats)
{
	size_t		i;
	t_stack_mv	next_mv;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] > stats.frt_qrt && a->tab[i] <= stats.med)
		{
			next_mv = find_shortest_to_top(*a, a->tab[i]);
			if (next_mv.forward)
				while (next_mv.nbr--)
					ra(a);
			else
				while (next_mv.nbr--)
					rra(a);
			pb(a, b);
			i = -1;
		}
	}
}

void	third_quarter(t_stack *a, t_stack *b, t_med_qrt stats)
{
	size_t		i;
	t_stack_mv	next_mv;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] > stats.med && a->tab[i] <= stats.trd_qrt)
		{
			next_mv = find_shortest_to_top(*a, a->tab[i]);
			if (next_mv.forward)
				while (next_mv.nbr--)
					ra(a);
			else
				while (next_mv.nbr--)
					rra(a);
			pb(a, b);
			i = -1;
		}
	}
}

void	fourth_quarter(t_stack *a, t_stack *b, t_med_qrt stats)
{
	size_t		i;
	t_stack_mv	next_mv;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] > stats.trd_qrt)
		{
			next_mv = find_shortest_to_top(*a, a->tab[i]);
			if (next_mv.forward)
				while (next_mv.nbr--)
					ra(a);
			else
				while (next_mv.nbr--)
					rra(a);
			pb(a, b);
			i = -1;
		}
	}
}

void	quarter_sort(t_stack *a, t_stack *b)
{
	int			index;
	t_stack_mv	next_mv;
	t_med_qrt	stats;

	find_fst_qrt_med_trd_qrt(*a, &stats);
	first_quarter(a, b, stats);
	sort_b(a, b);
	fourth_quarter(a, b, stats);
	sort_b(a, b);
	third_quarter(a, b, stats);
	sort_b(a, b);
	second_quarter(a, b, stats);
	sort_b(a, b);
	index = find_lowest(a);
	next_mv = find_shortest_to_top(*a, a->tab[index]);
	if (next_mv.forward)
		while (next_mv.nbr--)
			ra(a);
	else
		while (next_mv.nbr--)
			rra(a);
}