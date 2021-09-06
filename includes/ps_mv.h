/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mv.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:28:28 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/06 11:34:26 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MV_H
# define PS_MV_H
# include "structs/t_stack.h"
# include <stdbool.h>

void	s(t_stack *stk, char c, bool output);
void	sa(t_stack *a, t_stack *b, bool output);
void	sb(t_stack *a, t_stack *b, bool output);
void	ss(t_stack *a, t_stack *b, bool output);
void	pa(t_stack *a, t_stack *b, bool output);
void	pb(t_stack *a, t_stack *b, bool output);
void	ra(t_stack *a, t_stack *b, bool output);
void	rb(t_stack *a, t_stack *b, bool output);
void	rr(t_stack *a, t_stack *b, bool output);
void	rra(t_stack *a, t_stack *b, bool output);
void	rrb(t_stack *a, t_stack *b, bool output);
void	rrr(t_stack *a, t_stack *b, bool output);
#endif