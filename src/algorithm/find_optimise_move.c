/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimise_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:04:53 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/10 03:54:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "limit.h"

static t_head *duplicate_head(t_head *head)
{
    t_head *head_cpy;

    head_cpy = malloc(sizeof(t_head));
    if (!head_cpy)
    {
        ft_putstr_fd("malloc head failed bozo", 2);
        return (NULL);
    }
    head_cpy->stack_a = malloc(head->size * sizeof(int));
    head_cpy->stack_b = malloc(head->size * sizeof(int));
    if (!head_cpy->stack_a || !head_cpy->stack_b)
    {
        ft_putstr_fd("malloc failed bozo", 2);
        if (head_cpy->stack_a)
            free(head_cpy->stack_a);
        if (head_cpy->stack_b)
            free(head_cpy->stack_b);
        free(head_cpy);
        return (NULL);
    }
    ft_memcpy(head_cpy->stack_a, head->stack_a, head->size * sizeof(int));
    ft_memcpy(head_cpy->stack_b, head->stack_b, head->size * sizeof(int));

    head_cpy->size_a = head->size_a;
    head_cpy->size_b = head->size_b;
    head_cpy->size = head->size;
    return(head_cpy);
}


int silent_push_lowest_cost_to_a(t_head *head, int index)
{
    int cost;
    int count;

    count = 0;
    cost = index_to_place_in_a(head, head->stack_b[index]);
    if (cost == -1)
    {
        silent_push(head, 'A');
        return (1);
    }
    else if (cost < (head->size_a / 2))
    {
        while (cost)
        {
            silent_reverse_rotate(head, 'A');
            count++;
            cost--;
        }
        silent_push(head, 'A');
    }
    else
    {
        while (cost < head->size_a)
        {
            count++;
            silent_rotate(head, 'A');
            cost++;
        }
        silent_push(head, 'A');
    }
    return (count + 1);
}

static int silent_up_index_on_top_b(t_head *head, int index)
{
    int nb;
    int count;

    nb = head->stack_b[index];
    count = 0;
    if (index > (head->size_b / 2))
    {
        while(head->stack_b[head->size_b - 1] != nb)
        {
            silent_rotate(head, 'B');
            count++;
        }
    }
    else
    {
        while(head->stack_b[head->size_b - 1] != nb)
        {
            silent_reverse_rotate(head, 'B');
            count++;
        }
    }
    return (count);
}

int calculate_cost(t_head *head, int index)
{
    return (silent_up_index_on_top_b(head, index) + silent_push_lowest_cost_to_a(head, head->size_b - 1));
}

int find_lowest_cost(t_head *head, int depth)
{
    t_head *head_cpy;
    int i;
    int lowest;
    int lowest_index;
    int tmp;

    if (depth <= 0)
        return (0);
    i = (head->size_b - 1);
    lowest_index = -1;
    head_cpy = duplicate_head(head);
    if (!head_cpy)
        return (MIN_INT);
    while (i >= 0)
    {
        tmp = calculate_cost(head_cpy, i) + find_lowest_cost(head_cpy, depth - 1);
		ft_putnbr_fd(tmp, 1);
        ft_putstr_fd("\n", 1);
        if (lowest_index == -1 || tmp < lowest)
        {
            lowest_index = i;
            lowest = tmp;
        }
        ft_memcpy(head_cpy->stack_a, head->stack_a, head->size * sizeof(int));
        ft_memcpy(head_cpy->stack_b, head->stack_b, head->size * sizeof(int));
        head_cpy->size_a = head->size_a;
        head_cpy->size_b = head->size_b;
        i--;
    }
    free(head_cpy->stack_a);
    free(head_cpy->stack_b);
    free(head_cpy);
    return (lowest_index);
}

