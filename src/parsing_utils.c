/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:42:15 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/03 20:42:52 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
