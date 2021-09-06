/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:18:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 11:35:32 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "structs/t_stack.h"
#include "ps_mv.h"
#include "../libs/libft/includes/libft.h"

void	r_r(t_stack *stk, char c, bool output)
{
	int	tmp;

	if (stk->size < 3)
		return (s(stk, c, output));
	tmp = stk->tab[stk->size - 1];
	ft_memmove(&stk->tab[1], &stk->tab[0], (stk->size - 1) * sizeof(int));
	stk->tab[0] = tmp;
	if (output && c)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rra(t_stack *a, t_stack *b, bool output)
{
	(void)b;
	r_r(a, 'a', output);
}

void	rrb(t_stack *a, t_stack *b, bool output)
{
	(void)a;
	r_r(b, 'b', output);
}

void	rrr(t_stack *a, t_stack *b, bool output)
{
	r_r(a, 0, output);
	r_r(b, 0, output);
	if (output)
		write(1, "rrr\n", 4);
}
