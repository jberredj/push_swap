/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:38:39 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/16 15:06:45 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"

static int	string_is_nbr(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	check_for_int_max(char *str)
{
	size_t	len;
	char	*int_max;
	int		val_cmp[2];

	int_max = "2147483647";
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			int_max = "2147483648";
		str++;
	}
	len = ft_strlen(str);
	if (len > 10)
		return (1);
	else if (len == 10)
	{
		while (*str)
		{
			val_cmp[0] = (int)(*str++ - '0');
			val_cmp[1] = (int)(*int_max++ - '0');
			if (val_cmp[0] > val_cmp[1])
				return (-1);
		}
	}
	return (0);
}

int	malloc_stacks(t_stack *a, t_stack *b, size_t nmemb)
{
	a->tab = (int *)ft_calloc(nmemb, sizeof(int));
	if (!a->tab)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	b->tab = (int *)ft_calloc(nmemb, sizeof(int));
	if (!b->tab)
	{
		free(a->tab);
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	a->max_size = nmemb;
	b->max_size = nmemb;
	a->size = 0;
	b->size = 0;
	return (0);
}

int	fill_stack_a(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) >= 10)
			if (check_for_int_max(argv[i]))
				return (-1);
		if (string_is_nbr(argv[i]))
			a->tab[i - 1] = ft_atoi(argv[i]);
		else
			return (-1);
		a->size++;
	}
	return (0);
}
