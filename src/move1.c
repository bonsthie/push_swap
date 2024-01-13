/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:44:52 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/14 00:04:28 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	push(t_head *head, char stack_name)
{
	if (stack_name == 'A' && head->size_b)
	{
		head->stack_a[head->size_a++] = head->stack_b[--head->size_b];
		write(1, "pa\n", 3);
	}
	else if (stack_name == 'B' && head->size_a)
	{
		head->stack_b[head->size_b++] = head->stack_a[--head->size_a];
		write(1, "pb\n", 3);
	}
}

static int	swap_stack(int *stack, int size)
{
	if (size < 2)
		return (1);
	ft_swap(&stack[size - 1], &stack[size - 2]);
	return (0);
}

void	swap(t_head *head, char stack_name)
{
	if (stack_name == 'A')
	{
		if (!swap_stack(head->stack_a, head->size_a))
			write(1, "sa\n", 3);
	}
	else if (stack_name == 'B')
	{
		if (!swap_stack(head->stack_b, head->size_b))
			write(1, "sb\n", 3);
	}
	else if (stack_name == BOTH)
	{
		if (!swap_stack(head->stack_a, head->size_a)
			&& !swap_stack(head->stack_b, head->size_b))
			write(1, "ss\n", 3);
	}
}
