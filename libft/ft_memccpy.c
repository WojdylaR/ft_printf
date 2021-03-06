/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:18:27 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:18:30 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n > i && str[i] != (unsigned char)c)
	{
		dst[i] = str[i];
		i++;
	}
	if (str[i] == (unsigned char)c)
	{
		dst[i] = str[i];
		return (dst + i + 1);
	}
	return (NULL);
}
