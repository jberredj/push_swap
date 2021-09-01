/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:58:27 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/27 13:16:01 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
#include "sorters.h"

void	move_to_top(t_stack *a, t_stack *b, size_t index)
{
	t_stack_mv	next_mv;
	next_mv = find_shortest_to_top(*a, a->tab[index]);
	if (next_mv.forward)
		while (next_mv.nbr--)
			ra(a);
	else
		while (next_mv.nbr--)
			rra(a);
	pb(a, b);
}

void	first_half(t_stack *a, t_stack *b, t_med_qrt stats)
{
	size_t		i;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] <= stats.med)
		{
			move_to_top(a, b, i);
			i = -1;
		}
		else if (a->tab[(a->size - 1) - i] <= stats.med)
		{
			move_to_top(a, b, (a->size - 1) - i);
			i = -1;
		}
	}
}

void	move_chunck(t_stack *a, t_stack *b, int min_ch, int max_ch)
{
	size_t		i;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] > min_ch && a->tab[i] < max_ch)
		{
			move_to_top(a, b, i);
			i = -1;
		}
		else if (a->tab[(a->size - 1) - i] > min_ch
		&& a->tab[(a->size - 1) - i] < max_ch)
		{
			move_to_top(a, b, (a->size - 1) - i);
			i = -1;
		}
	}
}

void	second_half(t_stack *a, t_stack *b, t_med_qrt stats)
{
	size_t		i;
	t_stack_mv	next_mv;

	i = -1;
	while (++i < a->size)
	{
		if (a->tab[i] > stats.med)
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

// void	half_sort(t_stack *a, t_stack *b)
// {
// 	int			index;
// 	t_stack_mv	next_mv;
// 	t_med_qrt	stats;

// 	find_fst_qrt_med_trd_qrt(*a, &stats);
// 	first_half(a, b, stats);
// 	sort_b(a, b);
// 	second_half(a, b, stats);
// 	sort_b(a, b);
// 	index = find_lowest(a);
// 	next_mv = find_shortest_to_top(*a, a->tab[index]);
// 	if (next_mv.forward)
// 		while (next_mv.nbr--)
// 			ra(a);
// 	else
// 		while (next_mv.nbr--)
// 			rra(a);
// }

int	get_chunks(t_stack stk, size_t nbr_ch, t_chunks *chunks)
{
	int		i;
	int		*sorted_array;
	size_t	ch_len;

	sorted_array = (int *)malloc(stk.size * sizeof(int));
	if (!sorted_array)
		return (-1);
	chunks->ch_vals = (int *)malloc(nbr_ch + 1 * sizeof(int));
	if (!sorted_array)
		return (-1);
	ft_memcpy(sorted_array, stk.tab, stk.size * sizeof(int));
	sort_array(sorted_array, stk.size);
	ch_len = stk.size / nbr_ch;
	chunks->ch_vals[0] = sorted_array[0];
	i = 0;
	while (++i < (int)nbr_ch)
			chunks->ch_vals[i] = sorted_array[ch_len * i];
	chunks->ch_vals[i] = sorted_array[stk.size - 1];
	free(sorted_array);
	return (0);
}


void	half_sort(t_stack *a, t_stack *b)
{
	int			i;
	int			index;
	t_stack_mv	next_mv;
	t_chunks	chunks;

	get_chunks(*a, 2, &chunks);
	i = -1;
	while (++i < 2)
	{
		move_chunck(a, b, chunks.ch_vals[i] - 1 , chunks.ch_vals[i + 1] + 1);
		sort_b(a, b);
	}	
	free(chunks.ch_vals);
	index = find_lowest(a);
	next_mv = find_shortest_to_top(*a, a->tab[index]);
	if (next_mv.forward)
		while (next_mv.nbr--)
			ra(a);
	else
		while (next_mv.nbr--)
			rra(a);
}