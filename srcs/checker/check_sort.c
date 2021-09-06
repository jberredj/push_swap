/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:01:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 17:10:18 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
#include "sorters.h"
#include "push_swap.h"

static int	move_selector(char *str, t_stack *a, t_stack *b)
{
	if (ft_strncmp(str, "rra", 4) == 0)
		rra(a, b, false);
	else if (ft_strncmp(str, "rrb", 4) == 0)
		rrb(a, b, false);
	else if (ft_strncmp(str, "rrr", 4) == 0)
		rrr(a, b, false);
	else if (ft_strncmp(str, "sa", 3) == 0)
		sa(a, b, false);
	else if (ft_strncmp(str, "sb", 3) == 0)
		sb(a, b, false);
	else if (ft_strncmp(str, "ss", 3) == 0)
		ss(a, b, false);
	else if (ft_strncmp(str, "pa", 3) == 0)
		pa(a, b, false);
	else if (ft_strncmp(str, "pb", 3) == 0)
		pb(a, b, false);
	else if (ft_strncmp(str, "ra", 3) == 0)
		ra(a, b, false);
	else if (ft_strncmp(str, "rb", 3) == 0)
		rb(a, b, false);
	else if (ft_strncmp(str, "rr", 3) == 0)
		rr(a, b, false);
	else
		return (-1);
	return (0);
}

int	check_sort(t_stack *a, t_stack *b)
{
	char	*line;
	int		read_all;
	bool	first_read;

	line = NULL;
	read_all = 0;
	first_read = true;
	while (!read_all)
	{
		read_all = !get_next_line(0, &line);
		if (move_selector(line, a, b))
		{
			if ((!*line && first_read && read_all))
				return (0);
			free(line);
			if (read_all)
				continue ;
			return (-1);
		}
		first_read = false;
		free(line);
	}
	return (0);
}
