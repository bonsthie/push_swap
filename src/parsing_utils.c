/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:42:15 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/10 08:41:23 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_parse(char ***parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse[i])
	{
		j = 0;
		while (parse[i][j])
		{
			free(parse[i][j]);
			j++;
		}
		free(parse[i]);
		i++;
	}
	free(parse);
}

void	free_stack(t_head *head)
{
	if (head->stack_a)
		free(head->stack_a);
	if (head->stack_b)
		free(head->stack_b);
	if (head)
		free(head);
}
