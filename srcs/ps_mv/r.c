/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:18:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/03 11:20:21 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "../libs/libft/includes/libft.h"

void	r(t_stack *stk, char c)
{
	int	tmp;

	if (stk->size < 3)
		return (s(stk, c));
	tmp = stk->tab[0];
	ft_memmove(&stk->tab[0], &stk->tab[1], (stk->size - 1) * sizeof(int));
	stk->tab[stk->size - 1] = tmp;
	write(1, "r", 1);
	if (c)
	{
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	r(a, 'a');
}

void	rb(t_stack *a, t_stack *b)
{
	(void)a;
	r(b, 'b');
}

void	rr(t_stack *a, t_stack *b)
{
	r(a, 0);
	r(b, 0);
	write(1, "\n", 1);
}
