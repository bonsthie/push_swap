/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicotomie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:32:07 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/10 05:27:36 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limit.h"
#include "push_swap.h"

static void	ft_sort(int *list, int list_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < list_size)
	{
		j = i + 1;
		while (j < list_size)
		{
			if (list[j] < list[i])
				ft_swap(&list[j], &list[i]);
			j++;
		}
		i++;
	}
}

static double	find_median(int *list, int list_size)
{
	int		*list_sort;
	double	median;

	list_sort = malloc(list_size * sizeof(int));
	if (!list_sort)
		return (MIN_INT - 1);
	ft_memcpy(list_sort, list, list_size * sizeof(int));
	ft_sort(list_sort, list_size);
	if (list_size % 2 == 1)
		median = list_sort[(list_size + 1) / 2];
	else
		median = (double)(list_sort[list_size / 2] + list_sort[(list_size + 1)
				/ 2]) / 2.0;
	free(list_sort);
	return (median);
}

void	dicotomie(t_head *head)
{
	double	median;

	while (head->size_a > 3)
	{
		median = find_median(head->stack_a, head->size_a);
		if (median < MIN_INT)
		{
			ft_putstr_fd("error [malloc failed when finding the median]", 2);
			return ;
		}
		while (head->stack_a[head->size_a - 1] != (int)median)
		{
			if (head->stack_a[head->size_a - 1] > median)
				push(head, 'B');
			else
				rotate(head, 'A');
		}
		if (head->size_a > 3)
			push(head, 'B');
	}
}
