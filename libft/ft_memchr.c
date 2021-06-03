/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:18:33 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:18:34 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dst[i] == (unsigned char)c)
			return (dst + i);
		i++;
	}
	return (NULL);
}
