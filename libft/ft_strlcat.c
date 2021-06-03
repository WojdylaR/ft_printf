/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:19:51 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:19:52 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
	{
		while (src[j])
			j++;
		return (size + j);
	}
	while (src[j])
	{
		if (size >= i)
			dst[i] = src[j];
		i++;
		j++;
		if (i == size)
			dst[i - 1] = 0;
	}
	dst[i] = 0;
	return (i);
}
