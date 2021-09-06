/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:16:01 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 15:47:12 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/includes/libft.h"
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "sorters.h"
#include "insertion_sort.h"
#include <stdbool.h>
#include <stdint.h>
#ifndef TEST_MV_NBR
# define TEST_MV_NBR 500
#endif

static t_dstk_mv	select_lowest(t_dstk_mv *move, int nbr)
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

static void	neg_move_to_zero(t_dstk_mv *moves, int nbr)
{
	int	i;

	i = -1;
	while (++i < nbr)
	{
		if (moves[i].a_nbr < 0)
			moves[i].a_nbr = 0;
		if (moves[i].b_nbr < 0)
			moves[i].b_nbr = 0;
		if (moves[i].comb < 0)
			moves[i].comb = 0;
	}
}

static void	blank_moves(t_dstk_mv *moves, size_t nbr)
{
	int	i;

	i = -1;
	while (++i < (int)nbr)
	{
		moves[i].a_nbr = 0;
		moves[i].b_nbr = 0;
		moves[i].comb = 0;
		moves[i].type = 0;
	}
}

static void	optimize_move(t_dstk_mv *moves, int nbr)
{
	int	i;

	i = -1;
	while (++i < nbr)
	{
		if ((moves[i].type == SS) || (moves[i].type == RR)
			|| (moves[i].type == RRR))
		{
			while (moves[i].a_nbr > 0 && moves[i].b_nbr > 0)
			{
				moves[i].a_nbr--;
				moves[i].b_nbr--;
				moves[i].comb++;
			}
		}
	}
}

t_dstk_mv	find_lowest_move(t_stack *a, t_stack *b)
{
	int			i;
	int			j;
	t_dstk_mv	moves[TEST_MV_NBR];

	blank_moves(moves, TEST_MV_NBR);
	i = -1;
	while (++i < TEST_MV_NBR / 2 && i < (int)a->size)
		moves[i] = test_move(i, a, b);
	j = a->size - i;
	while (++j < (int)a->size && i < TEST_MV_NBR)
		moves[i++] = test_move(j, a, b);
	optimize_move(moves, TEST_MV_NBR);
	neg_move_to_zero(moves, TEST_MV_NBR);
	return (select_lowest(moves, TEST_MV_NBR));
}
