/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:26:55 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/05 18:02:18 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void free_parse(char ***parse);

static int verif_value_strs(char **strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		if (strs[i][0] == '+' || strs[i][0] == '-')
			j++;
		while (strs[i][j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static char ***ft_parse(int size, char **strs, int *stack_size)
{
	char ***parse;
    int     tmp;
	int i;

	parse = ft_calloc(size, sizeof(char**));
	if (!parse)
		return (NULL);
	i = 1;
    *stack_size = 0;
	while (i < size)
	{
		parse[i - 1] = ft_split(strs[i], ' ');
		if (!parse[i - 1])
		{
            write(2, "Error : [split error]", 21);
			free_parse(parse);
			return (NULL);
		}
        tmp = verif_value_strs(parse[i -1]);
		if (tmp == -1)
		{
            write(2, "Error : [wrong value]", 21);
			free_parse(parse);
			return (NULL);
		}
        i++;
        *stack_size += tmp;
	}
	return (parse);
}

static void fill_stack(int *stack, char ***parse, int stack_size)
{
    int j;
    int k;

    j = 0;
    while (parse[j])
    {
        k = 0;
        while(parse[j][k])
        {
			stack_size--;
            stack[stack_size] = ft_atoi(parse[j][k]);
            k++;
        }
        j++;
    }
}

static t_head *create_stack(char ***parse, int stack_size)
{
    t_head *head;

    head = malloc(sizeof(t_head));
    if (!head)
        return (NULL);
    head->stack_a = ft_calloc(stack_size, sizeof(int));
    head->stack_b = ft_calloc(stack_size, sizeof(int));
    if (!head->stack_a || !head->stack_b)
    {
        write(2, "Error : [stack allocation]", 26);
        free(head);
        if (head->stack_a)
            free(head->stack_a);
        if (head->stack_b)
            free(head->stack_b);
        return (NULL);
    }
    head->size_a = stack_size;
    head->size = stack_size;
    head->size_b = 0;
    fill_stack(head->stack_a, parse, stack_size);
    return (head);
}

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
        write(2, "Error : [stack allocation]", 26);
		free_parse(parse);
		return (NULL);
	}
	head = create_stack(parse, size_stack);
    free_parse(parse);
    if (!head)
		return (NULL);
	return (head);
}
