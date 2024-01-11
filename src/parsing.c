/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:26:55 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/11 23:41:02 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "limit.h"

static int	verif_value_strs(char **strs)
{
	long long tmp;
	int	i;
	int	j;

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

void pop(void *content)
{
	if (content)
		free(content);
}

int duplicate(t_list *node, int nb)
{
	while (node)
	{
		if (nb == *(long *)node->content)
			return (1);
		node = node->next;
	}
	return (0);
}

int fill_node(t_list **head, char **strs)
{
	int *value;
	int	i;

	if (!strs)
		return (0);
	i = 0;
	if (verif_value_strs(strs))
		return (1);
	while(strs[i])
	{
		value = malloc(sizeof(int));
		if (!value)
			return (1);
		*value = ft_atoi(*strs);
		if (duplicate(*head, *value))
			return (1);
		ft_lstadd_back(head, ft_lstnew(value));
		i++;
	}
	return (0);
}

static t_list	*ft_parse(int size, char **strs)
{
	t_list	*head;
	char **values;
	int i;

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
	while(--stack_size)
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
	if (!parse || size_stack == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	head = create_stack(&parse, size_stack);
	ft_lstclear(&parse, pop);
	return (head);
}
