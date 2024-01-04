/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:03:20 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/04 00:08:30 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_sorted(int *stack, int stack_size)
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
