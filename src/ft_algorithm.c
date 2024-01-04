/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:11:13 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/04 01:16:45 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_algorithm(t_head *head)
{
    int i;
    int j;

    i = 0;
    while (head->size_a)
    {
        j = head->size_a;
        while (j)
        {
            if ((head->stack_a[head->size_a - 1] >> i) & 0x1)
                push(head, 'B');
            else
                rotate(head, 'A');
            j--;
        }
        i++;
    }
}
