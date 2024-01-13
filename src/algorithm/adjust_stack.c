/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:34:05 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 00:46:29 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reposition_biggest_at_the_bottom(t_head *head, int *stack,
		int stack_size, int biggest_index)
{
	int	biggest;

	biggest = stack[biggest_index];
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

void	adjust_stack_for_extremes(t_head *head, int *stack, int stack_size)
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
	reposition_biggest_at_the_bottom(head, stack, stack_size, biggest_index);
}
