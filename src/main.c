/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:06:36 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/10 08:22:12 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_head	*head;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	head = stack_init(ac, av);
	if (!head)
		return (1);
	ft_youenn_algorithm(head);
	free_stack(head);
	return (0);
}
