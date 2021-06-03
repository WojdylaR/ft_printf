/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:20:02 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:20:07 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		n;
	char		*dst;

	n = 0;
	if (!(s && f))
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (ft_strlen(s) > n)
	{
		dst[n] = f(n, s[n]);
		n++;
	}
	dst[n] = 0;
	return (dst);
}
