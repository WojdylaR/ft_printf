/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:18:37 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:18:43 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	if (n == 0)
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s11[i] == s22[i] && n - 1 > i)
		i++;
	return (s11[i] - s22[i]);
}
