/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:20:41 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:20:44 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!(s))
		return (NULL);
	i = ft_strlen(s);
	if (!(dst = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start > i || s[0] == 0)
	{
		dst[0] = 0;
		return (dst);
	}
	i = 0;
	while (len-- > 0 && s[start])
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = 0;
	return (dst);
}
