/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:32:40 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/06 13:15:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	uc;
	char			*last;
	size_t			i;

	i = 0;
	uc = (unsigned char) c;
	last = NULL;
	if (uc == '\0')
		return ((char *) &str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == uc)
			last = (char *) &str[i];
		i++;
	}
	return (last);
}
