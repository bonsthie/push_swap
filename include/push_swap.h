/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:09:50 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/06 20:51:34 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_head
{
	int *stack_a;
	int *stack_b;
	int	size_a;
	int size_b;
	int size;
} t_head;

#define BOTH 'C'

#define ABS(nb) nb > 0 ? nb : -nb

t_head *stack_init(int size, char **strs);

//move
void push(t_head *head, char stack_name);
void swap(t_head *head, char stack_name);
void rotate(t_head *head, char stack_name);
void reverse_rotate(t_head *head, char stack_name);

// algorithm
void dicotomie(t_head *head);
void ft_youenn_algorithm(t_head *head);

#endif
