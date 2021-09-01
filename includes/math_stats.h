/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_stats.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:18:44 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/27 12:12:16 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STATS_H
# define MATH_STATS_H
typedef struct s_med_qrt
{
	int	frt_qrt;
	int	med;
	int	trd_qrt;
}				t_med_qrt;
typedef struct s_chunks
{
	size_t	ch_nbr;
	int		*ch_vals;
}				t_chunks;

int		find_fst_qrt_med_trd_qrt(t_stack stk, t_med_qrt *dat);
void	sort_array(int *array, size_t len);

#endif