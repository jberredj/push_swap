/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:06:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/05 13:42:19 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	size_t	size;
	size_t	max_size;
	int		*tab;
}				t_stack;

typedef struct s_stack_mv
{
	int		nbr;
	bool	forward;
}				t_stack_mv;
#endif