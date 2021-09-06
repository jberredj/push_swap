/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:49:18 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 11:16:28 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"

void	remove_top(t_stack *s)
{
	if (s->size < 1)
		return ;
	ft_memmove(&s->tab[0], &s->tab[1], (s->size - 1) * sizeof(int));
	s->size--;
}

void	add_top(t_stack *s, int val)
{
	if (s->size + 1 > s->max_size)
		return ;
	if (s->size > 0)
		ft_memmove(&s->tab[1], &s->tab[0], (s->size) * sizeof(int));
	s->tab[0] = val;
	s->size++;
}

static void	p(t_stack *src, t_stack *dst, char c, bool output)
{
	int	tmp;

	if (src->size < 1)
		return ;
	tmp = src->tab[0];
	remove_top(src);
	add_top(dst, tmp);
	if (output)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	pa(t_stack *a, t_stack *b, bool output)
{
	p(b, a, 'a', output);
}

void	pb(t_stack *a, t_stack *b, bool output)
{
	p(a, b, 'b', output);
}
