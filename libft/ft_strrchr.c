/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:20:22 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:20:22 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	if (str[i] == c)
		return (str + i);
	i--;
	while (str[i] != c && i > 0)
		i--;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
