/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:03:07 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/06 17:10:39 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*dest;

	if (size && nitems * size / size != nitems)
		return (NULL);
	dest = malloc(nitems * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nitems * size);
	return (dest);
}
