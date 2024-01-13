/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:52:15 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/13 03:36:32 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

int		is_sorted(int *stack, int stack_size);

void	silent_push(t_head *head, char stack_name);
void	silent_swap(t_head *head, char stack_name);
void	silent_rotate(t_head *head, char stack_name);
void	silent_reverse_rotate(t_head *head, char stack_name);

int		do_swap(char *cmd, t_head *head);
int		do_push(char *cmd, t_head *head);
int		do_rotate(char *cmd, t_head *head);
int		do_reverse_rotate(char *cmd, t_head *head);

#endif
