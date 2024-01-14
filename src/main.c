/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:06:36 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 23:33:46 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_head	*head;

	head = stack_init(ac, av);
	if (!head)
		return (1);
	if (!is_sorted(head->stack_a, head->size_a))
		ft_youenn_algorithm(head);
	free_stack(head);
	return (0);
}
