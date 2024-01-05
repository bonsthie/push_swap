/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_youenn_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:28:08 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/06 00:00:36 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void sort_three_element_a(t_head *head)
{
	if (head->stack_a[1] > head->stack_a[0] && head->stack_a[1] > head->stack_a[2])
		reverse_rotate(head, 'A');
	if (head->stack_a[2] > head->stack_a[0] && head->stack_a[2] > head->stack_a[1])
		rotate(head, 'A');
	if (head->stack_a[2] > head->stack_a[1])
		swap(head, 'A');
}

int cost_to_place_in_a(t_head *head, int nb)
{
	int i;
	int closest;
	int closest_value;

	i = 0;
	closest = -1;
	closest_value = -1;
	while (i < head->size_a)
	{
		if (head->stack_a[i] > nb && (closest == -1 || head->stack_a[i] < closest_value))
		{
			closest = i;
			closest_value = head->stack_a[i];
		}
		i++;
	}
	if (closest == -1)
		return (-1);
	return (closest % (head->size_a / 2));
}

int find_lowest_cost(t_head *head)
{
	int tmp;
	int lowest_cost;
	int lowest_cost_index;
	int	i;

	lowest_cost = -1;
	lowest_cost = -1;
	i = 0;
	while(i < head->size_b)
	{
		tmp = i % (head->size_b / 2) + ABS(cost_to_place_in_a(head, head->stack_b[i]) * 2);
		if (tmp < lowest_cost || lowest_cost == -1)
		{
			lowest_cost = tmp;
			lowest_cost_index = i;
		}
		i++;
	}
	return (lowest_cost_index);
}

void push_lowest_cost(t_head *head, int index)
{
	int nb;

	nb = head->stack_b[index];
	ft_putnbr_fd(nb, 2);
	write(2, "\n", 1);
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
	index = cost_to_place_in_a(head, head->stack_b[index] + 1);
	nb = head->stack_a[ABS(index)];
	if (index == -1)
	{
		ft_putstr_fd("-1 case\n", 2);
		push(head, 'A');
		rotate(head, 'A');
	}
	else if (index > (head->size_a / 2))
	{
		ft_putstr_fd("> case\n", 2);
		while(head->stack_a[head->size_a - 1] != nb)
			rotate(head, 'A');		
		push(head, 'A');
		while(index)
		{
			ft_printf("1 %d\n", index);
			reverse_rotate(head, 'A');
			index--;
		}
	}
	else
	{
		ft_putstr_fd("< case\n", 2);
		while(head->stack_a[head->size_a - 1] != nb)
			reverse_rotate(head, 'A');
		push(head, 'A');
		while(index)
		{
			ft_printf("2 %d\n", index);
			rotate(head, 'A');
			index--;
		}
	}
}

void ft_youenn_algorithm(t_head *head)
{
	int lowest_cost;

	dicotomie(head);
	sort_three_element_a(head);
	while(head->size_b)
	{
		lowest_cost = find_lowest_cost(head);
		push_lowest_cost(head, lowest_cost);
	}

}

//19 15 5 12 18 1 7 4 16 10 8 3 9 6 14 17 11 2 20 13
