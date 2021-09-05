/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:40:50 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/05 13:41:44 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "structs/t_stack.h"

int	malloc_stacks(t_stack *a, t_stack *b, size_t nmemb);
int	fill_stack_a(int argc, char **argv, t_stack *a);
#endif