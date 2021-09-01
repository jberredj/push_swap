/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:07:57 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/31 16:52:53 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTERS_H
# define SORTERS_H
#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
int	roundup_divide(int nbr, int div);
int	find_in_stack(t_stack s, int val);
t_stack_mv	find_shortest_to_top(t_stack s, int val);
size_t find_biggest(t_stack *stk);
size_t find_lowest(t_stack *stk);
void	biggest_is_faster(t_stack *a, t_stack *b, t_stack_mv mv);
void	lowest_is_faster(t_stack *a, t_stack *b, t_stack_mv mv);
void	sort_b(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b);
#endif