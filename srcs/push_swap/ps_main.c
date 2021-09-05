/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:09:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/05 13:36:04 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
#include "sorters.h"
#include "push_swap.h"

int	is_sorted(t_stack stk)
{
	int	i;

	i = -1;
	while (++i < (int)stk.size - 1)
		if (stk.tab[i] > stk.tab[i + 1])
			return (0);
	return (1);
}

int	check_for_error(t_stack stk)
{
	int	i;
	int	j;

	j = -1;
	while (++j < (int)stk.size)
	{
		i = -1;
		while (++i < (int)stk.size)
		{
			if (stk.tab[i] == stk.tab[j] && i != j)
				return (1);
		}
	}
	return (0);
}

void	free_stacks(int	*a, int *b)
{
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (malloc_stacks(&a, &b, argc - 1))
		return (-1);
	if (fill_stack_a(argc, argv, &a) || check_for_error(a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stacks(a.tab, b.tab);
		return (-1);
	}
	if (!is_sorted(a) && a.size > 1)
	{
		if (a.size == 2)
			sort_2(&a);
		else if (a.size == 3)
			sort_3(&a);
		else if (a.size < 6)
			sort_4_5(&a, &b);
		else
			insertion_sort(&a, &b);
	}
	free_stacks(a.tab, b.tab);
	return (0);
}
