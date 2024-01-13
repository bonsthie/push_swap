/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_move1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:35:51 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 00:03:08 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	silent_push(t_head *head, char stack_name)
{
	if (stack_name == 'A' && head->size_b)
	{
		head->stack_a[head->size_a++] = head->stack_b[--head->size_b];
	}
	else if (stack_name == 'B' && head->size_a)
	{
		head->stack_b[head->size_b++] = head->stack_a[--head->size_a];
	}
}

static int	swap_stack(int *stack, int size)
{
	if (size < 2)
		return (1);
	ft_swap(&stack[size - 1], &stack[size - 2]);
	return (0);
}

void	silent_swap(t_head *head, char stack_name)
{
	if (stack_name == 'A')
	{
		swap_stack(head->stack_a, head->size_a);
	}
	else if (stack_name == 'B')
	{
		swap_stack(head->stack_b, head->size_b);
	}
	else if (stack_name == BOTH)
	{
		swap_stack(head->stack_a, head->size_a);
		swap_stack(head->stack_b, head->size_b);
	}
}
