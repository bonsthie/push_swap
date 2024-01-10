/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:03:20 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/10 05:28:58 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(int *stack, int stack_size)
{
	stack_size--;
	while (stack_size > 0)
	{
		if (stack[stack_size - 1] < stack[stack_size])
			return (0);
		stack_size--;
	}
	return (1);
}
