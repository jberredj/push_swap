/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:16:43 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/01 12:47:20 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/includes/libft.h"
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "sorters.h"
#include <stdbool.h>
#include <stdint.h>
typedef void (* func_ptr)(t_stack *, t_stack *);

#define SA 1
#define SB 2
#define SS 3
#define PA 4
#define PB 8
#define RA 16
#define RB 32
#define RR 48
#define RRA 64
#define RRB 128
#define RRR 192

typedef struct s_dstk_mv
{
	uint16_t	type; //Movement type flags on 9 last bits
	int		a_nbr;
	int		b_nbr;
	int		comb;
}                    t_dstk_mv;

void	select_move_func(uint16_t type, func_ptr *a, func_ptr *b, func_ptr *ab)
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

void	execute_move(t_stack *a, t_stack *b, t_dstk_mv mv)
{
	func_ptr	a_mv_func;
	func_ptr	b_mv_func;
	func_ptr	both_mv_func;

	a_mv_func = NULL;
	b_mv_func = NULL;
	both_mv_func = NULL;
	select_move_func(mv.type, &a_mv_func, &b_mv_func, &both_mv_func);
	while (both_mv_func && mv.comb-- > 0)
		both_mv_func(a, b);
	while (mv.a_nbr-- > 0)
		a_mv_func(a, b);
	while (mv.b_nbr-- > 0)
		b_mv_func(a, b);
	
}


void	optimize_move(t_dstk_mv *moves, int nbr)
{
	t_dstk_mv	_debug;
	int	i;

	i = -1;
	while (++i < nbr)
	{
		_debug = moves [i];
		if ((moves[i].type == SS) || (moves[i].type == RR) || (moves[i].type == RRR))
			while (moves[i].a_nbr > 0 && moves[i].b_nbr > 0)
			{
				moves[i].a_nbr--;
				moves[i].b_nbr--;
				moves[i].comb++;
			}
	}
}


void		blank_moves(t_dstk_mv *moves, size_t nbr)
{
	int i;

	i = -1;
	while (++i < (int)nbr)
	{
		moves[i].a_nbr = 0;
		moves[i].b_nbr = 0;
		moves[i].comb = 0;
		moves[i].type = 0;
	}
}

t_dstk_mv	combined_two_mv(t_stack_mv mv_a, t_stack_mv mv_b)
{
	t_dstk_mv new_mv;

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

int		find_in_between(t_stack stk, int val)
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

t_dstk_mv	test_move(int index, t_stack *a, t_stack *b)
{
	int			value;
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

t_dstk_mv	select_lowest(t_dstk_mv *move, int nbr)
{
	int		i;
	int		ret_index;
	size_t	lowest;
	size_t	curr;

	i = 0;
	ret_index = 0;
	lowest = move[0].a_nbr + move[0].b_nbr + move[0].comb;
	while (++i < nbr)
	{
		curr = move[i].a_nbr + move[i].b_nbr + move[i].comb;
		if (curr < lowest && move[i].type)
		{
			lowest = curr;
			ret_index = i;
		}
	}
	return (move[ret_index]);
}

void		neg_move_to_zero(t_dstk_mv *moves, int nbr)
{
	t_dstk_mv	_debug;
	int i;

	i = -1;
	while (++i < nbr)
	{
		_debug = moves[i];
		if (moves[i].a_nbr < 0)
			moves[i].a_nbr = 0;
		if (moves[i].b_nbr < 0)
			moves[i].b_nbr = 0;
		if (moves[i].comb < 0)
			moves[i].comb = 0;
	}
	
}

#define TEST_MV_NBR 100

t_dstk_mv	find_lowest_move(t_stack *a, t_stack *b)
{
	int			offset;
	int			i;
	int			j;
	t_dstk_mv	moves[TEST_MV_NBR];

	blank_moves(moves, TEST_MV_NBR);
	i = -1;
	while (++i < TEST_MV_NBR / 2 && i < (int)a->size)
		moves[i] = test_move(i, a, b);
	offset = i;
	j =  a->size - i;
	while (++j < (int)a->size && i < TEST_MV_NBR)
		moves[i++] = test_move(j, a, b);
	optimize_move(moves, TEST_MV_NBR);
	neg_move_to_zero(moves, TEST_MV_NBR);
	return (select_lowest(moves, TEST_MV_NBR));
}

void	insert_first_values(t_stack *a, t_stack *b)
{
	int value;

	value = a->tab[0];
	pb(a, b);
	if ((value < b->tab[1] && value > b->tab[2]))
		sb(a, b);
	rb(a, b);
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	t_dstk_mv	mv;
	t_stack_mv	last;
	size_t		index;

	pb(a, b);
	pb(a, b);
	if (b->tab[0] < b->tab[1])
		sb(a, b);
	insert_first_values(a, b);
	while (a->size)
	{
		mv = find_lowest_move(a, b);
		execute_move(a, b, mv);
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
	index = find_lowest(a);
	last = find_shortest_to_top(*a, a->tab[index]);
	if (last.forward)
		while (last.nbr--)
			ra(a, b);
	else
		while (last.nbr--)
			rra(a, b);
}