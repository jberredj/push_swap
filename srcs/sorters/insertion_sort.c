/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:16:43 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/16 15:44:11 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/includes/libft.h"
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "sorters.h"
#include "insertion_sort.h"
#include <stdbool.h>
#include <stdint.h>

static void	select_move_func(uint16_t type, t_func_ptr *a, t_func_ptr *b,
			t_func_ptr *ab)
{
	if (type & SA)
		*a = sa;
	if (type & SB)
		*b = sb;
	if (!(~type & SS))
		*ab = ss;
	if (type & RA)
		*a = ra;
	if (type & RB)
		*b = rb;
	if (!(~type & RR))
		*ab = rr;
	if (type & RRA)
		*a = rra;
	if (type & RRB)
		*b = rrb;
	if (!(~type & RRR))
		*ab = rrr;
}

static void	execute_move(t_stack *a, t_stack *b, t_dstk_mv mv)
{
	t_func_ptr	a_mv_func;
	t_func_ptr	b_mv_func;
	t_func_ptr	both_mv_func;

	a_mv_func = NULL;
	b_mv_func = NULL;
	both_mv_func = NULL;
	select_move_func(mv.type, &a_mv_func, &b_mv_func, &both_mv_func);
	while (both_mv_func && mv.comb-- > 0)
		both_mv_func(a, b, true);
	while (mv.a_nbr-- > 0)
		a_mv_func(a, b, true);
	while (mv.b_nbr-- > 0)
		b_mv_func(a, b, true);
}

static void	insert_first_values(t_stack *a, t_stack *b)
{
	int	value;

	value = a->tab[0];
	pb(a, b, true);
	if ((value < b->tab[1] && value > b->tab[2]))
		sb(a, b, true);
	rb(a, b, true);
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	t_dstk_mv	mv;
	t_stack_mv	last;
	size_t		index;

	pb(a, b, true);
	pb(a, b, true);
	if (b->tab[0] < b->tab[1])
		sb(a, b, true);
	insert_first_values(a, b);
	while (a->size)
	{
		mv = find_lowest_move(a, b);
		execute_move(a, b, mv);
		pb(a, b, true);
	}
	while (b->size)
		pa(a, b, true);
	index = find_lowest(a);
	last = find_shortest_to_top(*a, a->tab[index]);
	if (last.forward)
		while (last.nbr-- > 0)
			ra(a, b, true);
	else
		while (last.nbr-- > 0)
			rra(a, b, true);
}
