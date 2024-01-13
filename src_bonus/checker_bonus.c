/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:49:12 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/14 00:02:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

int	stack_action(char *cmd, t_head *head)
{
	if (cmd[0] == 'p')
		return (do_push(cmd + 1, head));
	else if (cmd[0] == 's')
		return (do_swap(cmd + 1, head));
	else if (cmd[0] == 'r')
	{
		if (cmd[1] == 'r' && cmd[2] != 0)
			return (do_reverse_rotate(cmd + 2, head));
		else
			return (do_rotate(cmd + 1, head));
	}
	return (1);
}

void	tester(t_head *head)
{
	char	*tmp;
	int		status;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			return ;
		status = stack_action(tmp, head);
		free(tmp);
		if (status == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return ;
		}
	}
}

int	main(int ac, char **av)
{
	t_head	*head;

	head = stack_init(ac, av);
	if (!head)
		return (1);
	tester(head);
	if (is_sorted(head->stack_a, head->size_a) && head->size_a == head->size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(head);
	return (0);
}