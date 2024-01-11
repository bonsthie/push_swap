/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_youenn_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:28:08 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/11 23:40:33 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	sort_three_element_a(t_head *head)
{
	if (head->size_a == 2)
	{
		if (head->stack_a[1] > head->stack_a[0])
			reverse_rotate(head, 'A');
		return ;
	}
	if ( head->stack_a[2] > head->stack_a[0]
		&& head->stack_a[2] > head->stack_a[1])
		rotate(head, 'A');
	if (head->stack_a[2] > head->stack_a[1])
		swap(head, 'A');
}

static void	up_index_on_top_b(t_head *head, int index)
{
	int	nb;

	nb = head->stack_b[index];
	if (index > (head->size_b / 2))
	{
		while (head->stack_b[head->size_b - 1] != nb)
			rotate(head, 'B');
	}
	else
	{
		while (head->stack_b[head->size_b - 1] != nb)
			reverse_rotate(head, 'B');
	}
}

static void	push_lowest_cost(t_head *head, int index)
{
	int	cost;

	cost = index_to_place_in_a(head, head->stack_b[index]);
	if (cost < (head->size_a / 2))
	{
		while (cost)
		{
			reverse_rotate(head, 'A');
			cost--;
		}
		push(head, 'A');
	}
	else
	{
		while (cost < head->size_a)
		{
			rotate(head, 'A');
			cost++;
		}
		push(head, 'A');
	}
}

static void	adjust_stack_for_extremes(t_head *head, int *stack, int stack_size)
{
	int	biggest;
	int	biggest_index;
	int	i;

	i = 0;
	biggest = stack[0];
	biggest_index = 0;
	while (i < stack_size)
	{
		if (stack[i] > biggest)
		{
			biggest_index = i;
			biggest = stack[i];
		}
		i++;
	}
	if (biggest_index > stack_size / 2)
	{
		while (stack[0] != biggest)
			rotate(head, 'A');
	}
	else
	{
		while (stack[0] != biggest)
			reverse_rotate(head, 'A');
	}
}

void	ft_youenn_algorithm(t_head *head)
{
	int	lowest_cost;

	if (head->size_a <= 1)
		return ;
	if (head->size_a > 3)
		dicotomie(head);
	sort_three_element_a(head);
	while (head->size_b)
	{
		lowest_cost = find_lowest_cost(head);
		up_index_on_top_b(head, lowest_cost);
		push_lowest_cost(head, head->size_b - 1);
	}
	if (head->size_a)
		adjust_stack_for_extremes(head, head->stack_a, head->size_a);
}
