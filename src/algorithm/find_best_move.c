/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:15:16 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/10 05:26:36 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limit.h"
#include "push_swap.h"

int	index_to_place_in_a(t_head *head, int nb)
{
	int	i;
	int	closest;
	int	closest_value;

	i = 0;
	closest = -1;
	closest_value = MAX_INT;
	while (i < head->size_a)
	{
		if (head->stack_a[i] < nb && (closest == -1
				|| head->stack_a[i] > closest_value))
		{
			closest = i;
			closest_value = head->stack_a[i];
		}
		i++;
	}
	return (closest);
}

int	cost_to_put_on_top(int index, int stack_size)
{
	if (index > (stack_size / 2))
		return (stack_size - index);
	return (index);
}

int	find_lowest_cost(t_head *head)
{
	int	tmp;
	int	lowest_cost;
	int	lowest_cost_index;
	int	i;

	lowest_cost = -1;
	i = 0;
	while (i < head->size_b)
	{
		tmp = cost_to_put_on_top(i, head->size_b)
			+ cost_to_put_on_top(index_to_place_in_a(head, head->stack_b[i]),
				head->size_a);
		if (tmp < lowest_cost || lowest_cost == -1)
		{
			lowest_cost = tmp;
			lowest_cost_index = i;
		}
		i++;
	}
	return (lowest_cost_index);
}
