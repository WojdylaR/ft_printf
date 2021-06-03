/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:41:06 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/07/01 17:49:05 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	u_nbr_len(unsigned int n)
{
	unsigned int len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char			*ft_utoa2(char *res, unsigned int n)
{
	unsigned int		len;

	len = 0;
	len += u_nbr_len(n);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = 0;
	while (n > 0)
	{
		len--;
		res[len] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}

char				*ft_utoa(unsigned int n)
{
	char	*res;

	res = 0;
	if (n == 0)
		res = ft_strdup("0");
	else
	{
		if (!(res = ft_utoa2(res, n)))
			return (0);
	}
	return (res);
}

int					condition_7(t_arg *list, int x, const char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (list->type == 's' && check_point(str) == 1)
		new_res(list);
	i = x > (int)ft_strlen(list->res) ? x : (int)ft_strlen(list->res);
	if (ft_strchr("id", list->type) && list->res[0] == '-')
	{
		x--;
		temp = ft_strdup(list->res);
		free(list->res);
		list->res = ft_substr(temp, 1, (int)ft_strlen(temp) - 1);
		free(temp);
		ft_putchar_fd('-', 1);
	}
	while (x-- > (int)ft_strlen(list->res))
		ft_putchar_fd('0', 1);
	ft_putstr_fd(list->res, 1);
	return (i);
}

char				*ft_test_s(t_arg *list, va_list list_arg, const char *str)
{
	if (list->prec != 0)
		return (ft_strdup(va_arg(list_arg, char *)));
	if (check_point(str) == 0)
		return (ft_strdup(va_arg(list_arg, char *)));
	return (ft_strdup(""));
}
