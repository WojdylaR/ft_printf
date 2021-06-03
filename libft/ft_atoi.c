/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:16:36 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:16:41 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	long r;
	long i;
	long n;

	i = 0;
	r = 0;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	if (n == 1)
		r = r * (-1);
	return (r);
}
