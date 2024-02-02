/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:06:36 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/02 19:54:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_head	*head;

	if (ac == 1)
		return (0);
	head = stack_init(ac, av);
	if (!head)
		return (1);
	if (!is_sorted(head->stack_a, head->size_a))
		ft_youenn_algorithm(head);
	free_stack(head);
	return (0);
}
