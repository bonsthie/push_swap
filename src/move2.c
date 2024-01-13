/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:04:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 00:05:09 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

void	rotate(t_head *head, char stack_name)
{
	if (stack_name == 'A')
	{
		rotate_stack(head->stack_a, head->size_a);
		write(1, "ra\n", 3);
	}
	if (stack_name == 'B')
	{
		rotate_stack(head->stack_b, head->size_b);
		write(1, "rb\n", 3);
	}
	if (stack_name == BOTH)
	{
		rotate_stack(head->stack_b, head->size_b);
		rotate_stack(head->stack_a, head->size_a);
		write(1, "rr\n", 3);
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

void	reverse_rotate(t_head *head, char stack_name)
{
	if (stack_name == 'A')
	{
		reverse_rotate_stack(head->stack_a, head->size_a);
		write(1, "rra\n", 4);
	}
	if (stack_name == 'B')
	{
		reverse_rotate_stack(head->stack_b, head->size_b);
		write(1, "rrb\n", 4);
	}
	if (stack_name == BOTH)
	{
		reverse_rotate_stack(head->stack_b, head->size_b);
		reverse_rotate_stack(head->stack_a, head->size_a);
		write(1, "rrr\n", 4);
	}
}
