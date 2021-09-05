/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:18:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/03 11:22:37 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "../libs/libft/includes/libft.h"

void	r_r(t_stack *stk, char c)
{
	int	tmp;

	if (stk->size < 3)
		return (s(stk, c));
	tmp = stk->tab[stk->size - 1];
	ft_memmove(&stk->tab[1], &stk->tab[0], (stk->size - 1) * sizeof(int));
	stk->tab[0] = tmp;
	if (c)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rra(t_stack *a, t_stack *b)
{
	(void)b;
	r_r(a, 'a');
}

void	rrb(t_stack *a, t_stack *b)
{
	(void)a;
	r_r(b, 'b');
}

void	rrr(t_stack *a, t_stack *b)
{
	r_r(a, 0);
	r_r(b, 0);
	write(1, "rrr\n", 4);
}
