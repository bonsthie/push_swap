/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:13:42 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/08 18:00:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int *find_lis(int *stack, int size, int *lis_length) {
  int *dp, *prev, *lis;
  int i, j, max_idx, temp_idx;

  dp = malloc(size * sizeof(int));
  prev = malloc(size * sizeof(int));
  lis = malloc(size * sizeof(int));
  if (!dp || !prev || !lis) {
    free(dp);
    free(prev);
    free(lis);
    return NULL;
  }

  for (i = 0; i < size; i++) {
    dp[i] = 1;
    prev[i] = -1;
    for (j = 0; j < i; j++) {
      if (stack[j] < stack[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
  }

  max_idx = 0;
  for (i = 1; i < size; i++) {
    if (dp[i] > dp[max_idx])
      max_idx = i;
  }

  *lis_length = dp[max_idx];
  temp_idx = max_idx;
  while (temp_idx != -1) {
    lis[temp_idx] = 1;
    temp_idx = prev[temp_idx];
  }

  free(dp);
  free(prev);
  return lis;
}

void move_non_lis_elements(t_head *head) {
  int *lis, lis_length, i;

  lis = find_lis(head->stack_a, head->size_a, &lis_length);
  if (!lis) {
    ft_putstr_fd("Error: malloc failed in find_lis\n", 2);
    return;
  }

  i = head->size_a - 1;
  while (i >= 0) {
    if (!lis[i])
      push(head, 'B');
    else
      rotate(head, 'A');
    i--;
  }

  free(lis);
}
