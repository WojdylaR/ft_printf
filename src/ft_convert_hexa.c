/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:40:13 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/07/01 17:48:27 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long value, char *base)
{
	int						count;
	unsigned long long		tmp;
	char					*res;
	unsigned long long		base_length;

	base_length = ft_strlen(base);
	count = (value < 0) ? 2 : 1;
	tmp = (value < 0) ? -value : value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = (value < 0) ? -value : value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (value < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}

char	*ft_put_address(unsigned long long src)
{
	char *dst;

	if ((char *)src == NULL)
		return (ft_strdup("\0"));
	dst = ft_itoa_base(src, "0123456789abcdef");
	return (dst);
}
