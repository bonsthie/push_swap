/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:09:50 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/07 23:14:07 by bbonnet          ###   ########.fr       */
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

//silent move
void silent_push(t_head *head, char stack_name);
void silent_swap(t_head *head, char stack_name);
void silent_rotate(t_head *head, char stack_name);
void silent_reverse_rotate(t_head *head, char stack_name);

// algorithm
void dicotomie(t_head *head);
void move_non_lis_elements(t_head *head);
int index_to_place_in_a(t_head *head, int nb);
int find_lowest_cost(t_head *head, int depth);

void ft_youenn_algorithm(t_head *head);

#endif
