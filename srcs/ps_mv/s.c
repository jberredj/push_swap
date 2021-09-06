/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:42:42 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 11:24:16 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "structs/t_stack.h"

void	s(t_stack *stk, char c, bool output)
{
	int	tmp;

	if (stk->size < 1)
		return ;
	tmp = stk->tab[0];
	stk->tab[0] = stk->tab[1];
	stk->tab[1] = tmp;
	if (output && c)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	sa(t_stack *a, t_stack *b, bool output)
{
	(void)b;
	s(a, 'a', output);
}

void	sb(t_stack *a, t_stack *b, bool output)
{
	(void)a;
	s(b, 'b', output);
}

void	ss(t_stack *a, t_stack *b, bool output)
{
	s(a, 0, output);
	s(b, 0, output);
}
