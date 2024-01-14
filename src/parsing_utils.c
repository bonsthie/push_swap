/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:16:39 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 18:34:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limit.h"

static int	duplicate(t_list *node, int nb)
{
	while (node)
	{
		if (nb == *(long *)node->content)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	verif_value_strs(char **strs)
{
	long long	tmp;
	int			i;
	int			j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		if (strs[i][0] == '+' || strs[i][0] == '-')
			j++;
		tmp = ft_atoll(strs[i]);
		if (ft_strlen(strs[i]) >= 10 && (tmp > MAX_INT || tmp < MIN_INT))
			return (1);
		while (strs[i][j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_node(t_list **head, char **strs)
{
	int	*value;
	int	i;

	if (!strs)
		return (1);
	i = 0;
	if (verif_value_strs(strs))
		return (1);
	while (strs[i])
	{
		value = malloc(sizeof(int));
		if (!value)
			return (1);
		*value = ft_atoi(strs[i]);
		if (duplicate(*head, *value))
			return (1);
		ft_lstadd_back(head, ft_lstnew(value));
		i++;
	}
	return (0);
}
