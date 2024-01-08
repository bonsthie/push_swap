/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_youenn_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:28:08 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/07 23:45:28 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

void sort_three_element_a(t_head *head)
{
	if (head->stack_a[1] > head->stack_a[0] && head->stack_a[1] > head->stack_a[2])
		reverse_rotate(head, 'A');
	if (head->stack_a[2] > head->stack_a[0] && head->stack_a[2] > head->stack_a[1])
		rotate(head, 'A');
	if (head->stack_a[2] > head->stack_a[1])
		swap(head, 'A');
}

int index_to_place_in_a(t_head *head, int nb)
{
	int i;
	int closest;
	int closest_value;

	i = 0;
	closest = -1;
	closest_value = INT_MAX;
	while (i < head->size_a)
	{
		if (head->stack_a[i] < nb && (closest == -1 || head->stack_a[i] > closest_value))
		{
			closest = i;
			closest_value = head->stack_a[i];
		}
		i++;
	}
	if (closest == -1)
		return (-1);
	return (closest);
}

void push_lowest_cost_to_a(t_head *head, int index)
{
    int cost;

    cost = index_to_place_in_a(head, head->stack_b[index]);
    if (cost == -1)
        push(head, 'A');
    else if (cost < (head->size_a / 2))
    {
        while (cost)
        {
            reverse_rotate(head, 'A');
            cost--;
        }
        push(head, 'A');
    }
    else
    {
        while (cost < head->size_a)
        {
            rotate(head, 'A');
            cost++;
        }
        push(head, 'A');
    }
}

void up_index_on_top_b(t_head *head, int index)
{
    int nb;

    nb = head->stack_b[index];
    if (index == 0)
    {
        reverse_rotate(head, 'B');
    }
    else if (index > (head->size_b / 2))
    {
        int count = 0;
        while(head->stack_b[head->size_b - 1] != nb)
        {
            if (count >= head->size_b)
                return ;
            rotate(head, 'B');
            count++;
        }
    }
    else
    {
        while(head->stack_b[head->size_b - 1] != nb)
            reverse_rotate(head, 'B');
    }
}


void ft_youenn_algorithm(t_head *head)
{
	int lowest_cost;

	dicotomie(head);
    //move_non_lis_elements(head); 
    if (head->size_a == 3)
        sort_three_element_a(head);
    while(head->size_b)
	{
		lowest_cost = find_lowest_cost(head, 2);
        ft_putnbr_fd(lowest_cost, 2);
        int find = head->stack_b[lowest_cost];
        ft_putstr_fd("\n", 2);
        if (lowest_cost < 0)
        {
            ft_putstr_fd("error", 2);
            if (lowest_cost == INT_MIN)
                ft_putstr_fd("malloc faild", 2);
            return ;
        }
        up_index_on_top_b(head, lowest_cost);
		push_lowest_cost_to_a(head, head->size_b - 1);
        int push = head->stack_a[head->size_a - 1];
        if (find != push)
        {
            ft_putstr_fd("wrond one push find -> ", 2);
            ft_putnbr_fd(find, 2);
            ft_putstr_fd("push ->", 2);
            ft_putnbr_fd(push, 2);
            ft_putstr_fd("\n", 2);
        }
	}

}
