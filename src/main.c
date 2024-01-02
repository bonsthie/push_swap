/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:06:36 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/02 17:28:25 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void free_parse(char ***parse)
{
	int i;
	int j;

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

int verif_value_strs(char **strs)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (strs[i])
	{
		j = 0;
		if (strs[i][0] == '+' || strs[i][0] == '-')
			j++;
		while (strs[i][j])
		{
			if (ft_isdigit(strs[i][j]))
				return (1);
			j++;
		}
		count += j;
		i++;
	}
	return (0);
}

char ***ft_parse(int size, char **strs)
{
	char ***parse;
	int i;

	parse = ft_calloc(size, sizeof(char**));
	if (!parse)
		return (NULL);
	i = 1;
	while (i < size)
	{
		parse[i - 1] = ft_split(strs[i], ' ');
		if (!parse[i - 1])
		{
			free_parse(parse);
			return (NULL);
		}
		if (verif_value_strs(parse[i -1]))
		{
			free_parse(parse);
			return (NULL);
		}
	}
	return (parse);
}

int stack_size(char ***parse);

t_head *stack_init(int size, char **strs)
{
	t_head *head;
	char ***parse;
	int size_stack;


	parse = ft_parse(size, strs, &size_stack);
	if (!parse)
		return (NULL);
	if (size_stack == -1)
	{
		free_parse(parse);
		return (NULL);
	}
	head = create_stack(parse, size);
	return (head);
}

int main(int ac, char **av)
{
	t_head *head;

	head = stack_init(ac, av);
	if (head == NULL)
		return (1);
	return (0);

}
