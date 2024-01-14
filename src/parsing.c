/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:26:55 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/14 23:35:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_parse(int size, char **strs)
{
	t_list	*head;
	char	**values;
	int		i;

	i = 1;
	head = NULL;
	while (i < size)
	{
		values = ft_split(strs[i], ' ');
		if (fill_node(&head, values))
		{
			free_split(values);
			ft_lstclear(&head, pop);
			return (NULL);
		}
		free_split(values);
		i++;
	}
	return (head);
}

void	fill_stack(int *stack, int stack_size, t_list *lst)
{
	while (--stack_size)
	{
		stack[stack_size] = *((int *)(long *)lst->content);
		lst = lst->next;
	}
	stack[stack_size] = *((int *)(long *)lst->content);
}

static t_head	*create_stack(t_list **parse, int stack_size)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	if (!head)
		return (NULL);
	head->stack_a = ft_calloc(stack_size, sizeof(int));
	head->stack_b = ft_calloc(stack_size, sizeof(int));
	if (!head->stack_a || !head->stack_b)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(head);
		return (NULL);
	}
	head->size_a = stack_size;
	head->size = stack_size;
	head->size_b = 0;
	fill_stack(head->stack_a, stack_size, *parse);
	return (head);
}

t_head	*stack_init(int size, char **strs)
{
	t_head	*head;
	t_list	*parse;
	int		size_stack;

	parse = ft_parse(size, strs);
	if (parse)
		size_stack = ft_lstsize(parse);
	else
		size_stack = -1;
	if (!parse)
		return (NULL);
	if (size_stack == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	head = create_stack(&parse, size_stack);
	ft_lstclear(&parse, pop);
	return (head);
}
