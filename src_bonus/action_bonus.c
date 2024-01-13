/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:14:51 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 00:03:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

int	do_push(char *cmd, t_head *head)
{
	if (!ft_strcmp(cmd, "a\n"))
	{
		if (head->size_a < head->size && head->size_b != 0)
			silent_push(head, 'A');
		else
			return (1);
		return (0);
	}
	else if (!ft_strcmp(cmd, "b\n"))
	{
		if (head->size_b < head->size && head->size_a != 0)
			silent_push(head, 'B');
		else
			return (1);
		return (0);
	}
	return (1);
}

int	do_swap(char *cmd, t_head *head)
{
	if (!ft_strcmp(cmd, "a\n"))
	{
		if (head->size_a >= 2)
			silent_swap(head, 'A');
		else
			return (1);
		return (0);
	}
	else if (!ft_strcmp(cmd, "b\n"))
	{
		if (head->size_b >= 2)
			silent_swap(head, 'B');
		else
			return (1);
		return (0);
	}
	else if (!ft_strcmp(cmd, "s\n"))
	{
		if (head->size_a >= 2 && head->size_b >= 2)
			silent_swap(head, BOTH);
		else
			return (1);
		return (0);
	}
	return (1);
}

int	do_rotate(char *cmd, t_head *head)
{
	if (!ft_strcmp(cmd, "a\n"))
	{
		silent_rotate(head, 'A');
		return (0);
	}
	else if (!ft_strcmp(cmd, "b\n"))
	{
		silent_rotate(head, 'B');
		return (0);
	}
	else if (!ft_strcmp(cmd, "r\n"))
	{
		silent_rotate(head, BOTH);
		return (0);
	}
	return (1);
}

int	do_reverse_rotate(char *cmd, t_head *head)
{
	if (!ft_strcmp(cmd, "a\n"))
	{
		silent_reverse_rotate(head, 'A');
		return (0);
	}
	else if (!ft_strcmp(cmd, "b\n"))
	{
		silent_reverse_rotate(head, 'B');
		return (0);
	}
	else if (!ft_strcmp(cmd, "r\n"))
	{
		silent_reverse_rotate(head, BOTH);
		return (0);
	}
	return (1);
}
