/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:06:36 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/04 01:33:27 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"



int main(int ac, char **av)
{
    // todo check for double and int max/min
	t_head *head;

	head = stack_init(ac, av);
	if (!head)
		return (1);
    ft_algorithm(head);
    return (0);
}
