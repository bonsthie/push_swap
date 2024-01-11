/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:09:50 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/11 23:03:19 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_head
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	size;
}		t_head;

typedef struct s_node
{
	int	value;
	struct s_node *next;
} t_node;

# define BOTH 'C'

t_head	*stack_init(int size, char **strs);
//void	fill_stack(int *stack, t_list *lst);

void	free_stack(t_head *head);
void free_split(char **strs);

// move
void	push(t_head *head, char stack_name);
void	swap(t_head *head, char stack_name);
void	rotate(t_head *head, char stack_name);
void	reverse_rotate(t_head *head, char stack_name);

// algorithm
void	dicotomie(t_head *head);
int		find_lowest_cost(t_head *head);
int		index_to_place_in_a(t_head *head, int nb);
void	ft_youenn_algorithm(t_head *head);

#endif
