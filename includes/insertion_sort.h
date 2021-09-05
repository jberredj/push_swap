/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:45:52 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/05 13:42:55 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERTION_SORT_H
# define INSERTION_SORT_H
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 8
# define RA 16
# define RB 32
# define RR 48
# define RRA 64
# define RRB 128
# define RRR 192

typedef void (*	t_func_ptr)(t_stack *, t_stack *);

typedef struct s_dstk_mv
{
	uint16_t	type;
	int			a_nbr;
	int			b_nbr;
	int			comb;
}				t_dstk_mv;

void		half_sort(t_stack *a, t_stack *b);
void		quarter_sort(t_stack *a, t_stack *b);
t_dstk_mv	test_move(int index, t_stack *a, t_stack *b);
t_dstk_mv	find_lowest_move(t_stack *a, t_stack *b);
#endif