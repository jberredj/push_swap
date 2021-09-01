/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:04:52 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/27 12:12:18 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/libft/includes/libft.h"
#include "structs/t_stack.h"
#include "math_stats.h"

void	sort_array(int *array, size_t len)
{
	int		tmp;
	size_t	i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
	
}

int	find_fst_qrt_med_trd_qrt(t_stack stk, t_med_qrt *dat)
{
	int		*sorted_array;
	size_t	qrt_len;

	sorted_array = (int *)malloc(stk.size * sizeof(int));
	if (!sorted_array)
		return (-1);
	ft_memcpy(sorted_array, stk.tab, stk.size * sizeof(int));
	sort_array(sorted_array, stk.size);
	qrt_len = stk.size / 4;
	dat->frt_qrt = sorted_array[qrt_len];
	dat->med = sorted_array[qrt_len * 2];
	dat->trd_qrt = sorted_array[qrt_len * 3];
	free(sorted_array);
	return (0);
}