/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:19:54 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:19:55 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*dst;

	dst = (char *)dest;
	i = 0;
	if (!(dest && src))
		return (0);
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && size - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
