/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:09:50 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/04 00:39:19 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_node
{
	char **nums;
	struct s_node *next;
} t_node;

typedef struct s_head
{
	int *stack_a;
	int *stack_b;
	int	size_a;
	int size_b;
	int size;
} t_head;

#define BOTH 'C'

t_head *stack_init(int size, char **strs);

//move
void push(t_head *head, char stack_name);
void swap(t_head *head, char stack_name);
void rotate(t_head *head, char stack_name);
void reverse_rotate(t_head *head, char stack_name);

// algorithm
void ft_algorithm(t_head *head);

#endif
