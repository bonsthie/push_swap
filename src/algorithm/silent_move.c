/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:44:52 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/06 21:25:30 by bbonnet          ###   ########.fr       */
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

static void	rotate_stack(int *stack, int size)
{
	int	tmp;
	int	i;

	if (size < 2)
		return ;
	i = 0;
	tmp = stack[size - 1];
	while (i < size)
	{
		ft_swap(&tmp, &stack[i]);
		i++;
	}
	stack[0] = tmp;
}

void	silent_rotate(t_head *head, char stack_name)
{
	if (stack_name == 'A')
	{
		rotate_stack(head->stack_a, head->size_a);
	}
	if (stack_name == 'B')
	{
		rotate_stack(head->stack_b, head->size_b);
	}
	if (stack_name == BOTH)
	{
		rotate_stack(head->stack_b, head->size_b);
		rotate_stack(head->stack_a, head->size_a);
	}
}

static void	reverse_rotate_stack(int *stack, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	size--;
	while (size)
	{
		ft_swap(&tmp, &stack[size]);
		size--;
	}
	stack[0] = tmp;
}

void	silent_reverse_rotate(t_head *head, char stack_name)
{
	if (stack_name == 'A')
	{
		reverse_rotate_stack(head->stack_a, head->size_a);
	}
	if (stack_name == 'B')
	{
		reverse_rotate_stack(head->stack_b, head->size_b);
	}
	if (stack_name == BOTH)
	{
		reverse_rotate_stack(head->stack_b, head->size_b);
		reverse_rotate_stack(head->stack_a, head->size_a);
	}
}
