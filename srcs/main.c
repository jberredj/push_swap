/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:09:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/01 15:05:30 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_stack.h"
#include "../libs/libft/includes/libft.h"
#include "ps_mv.h"
#include "math_stats.h"
#include "sorters.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	half_sort(t_stack *a, t_stack *b);
void	quarter_sort(t_stack *a, t_stack *b);

void	print_stacks(t_stack a, t_stack b, size_t max_size)
{
	printf("STACKS CONTENT\n");
	for (size_t i = 0; i < max_size; i++)
	{
		printf("[%zu]\t", i);
		if (i < a.size)
			printf("%d", a.tab[i]);
		printf("\t|\t");
		if (i < b.size)
			printf("%d", b.tab[i]);
		printf("\n");
	}
	
}

int	malloc_stacks(t_stack *a, t_stack *b, size_t nmemb)
{
	a->tab = (int *)ft_calloc(nmemb, sizeof(int));
	if (!a->tab)
		return (-1);
	b->tab = (int *)ft_calloc(nmemb, sizeof(int));
	if (!b->tab)
	{
		free(a->tab);
		return (-1);
	}
	a->max_size = nmemb;
	b->max_size = nmemb;
	a->size = 0;
	b->size = 0;
	return (0);
}

int	string_is_nbr(char *str)
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

int	fill_stack_a(int argc, char **argv, t_stack *a)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (string_is_nbr(argv[i]))
			a->tab[i - 1] = ft_atoi(argv[i]);
		else
			return (-1);
		a->size++;
	}
	return (0);
}

int	useless(void)
{
	return(2);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (malloc_stacks(&a, &b, argc - 1))
		return (-1);
	if (fill_stack_a(argc, argv, &a))
	{
		free(a.tab);
		free(b.tab);
		return (-1);
	}
	insertion_sort(&a, &b);
	// print_stacks(a, b, a.max_size);
	// if (a.max_size <= 100)
	// 	half_sort(&a, &b);
	// else
	// 	quarter_sort(&a, &b);
	// print_stacks(a, b, a.max_size);
	return (0);
}