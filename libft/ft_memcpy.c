/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:18:47 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:18:48 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*dest;

	dest = dst;
	str = (char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	while (n > i)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
