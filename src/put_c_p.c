/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:14:29 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:14:13 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_char(unsigned int c)
{
	char *dst;

	if (!(dst = malloc(sizeof(char) + 1)))
		return (0);
	dst[0] = c;
	dst[1] = '\0';
	return (dst);
}

int		cczero(t_arg *list)
{
	int c;

	c = 0;
	ft_putchar_fd(0, 1);
	list->flag++;
	while (list->flag)
	{
		ft_putchar_fd(' ', 1);
		c++;
		list->flag++;
	}
	return (c);
}

int		czero(t_arg *list)
{
	int c;

	c = 1;
	if (!(list->flag))
		ft_putchar_fd(0, 1);
	else if (list->flag > 0)
	{
		list->flag--;
		while (list->flag)
		{
			ft_putchar_fd(' ', 1);
			c++;
			list->flag--;
		}
		ft_putchar_fd(0, 1);
	}
	else
		c = c + cczero(list);
	return (c);
}

int		condition_p1(t_arg *list, int i)
{
	if (list->flag == 0 && list->prec == 0)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(list->res, 1);
		return (i + (int)ft_strlen(list->res));
	}
	if (list->flag < 0)
	{
		ft_putstr_fd("0x", 1);
		while (-1 + list->prec-- >= (int)ft_strlen(list->res))
		{
			i++;
			ft_putchar_fd('0', 1);
		}
		ft_putstr_fd(list->res, 1);
		while (-list->flag++ >= (int)ft_strlen(list->res) + 3)
		{
			i++;
			ft_putchar_fd(' ', 1);
		}
	}
	return (i);
}

int		condition_p(t_arg *list, const char *str)
{
	int i;

	i = 2;
	if (list->res[0] == 0 && check_point(str) == 0)
		list->res[0] = '0';
	if (list->flag >= 0)
	{
		while (list->flag-- >= list->prec + 3 &&
				list->flag >= (int)ft_strlen(list->res) + 2)
		{
			i++;
			ft_putchar_fd(' ', 1);
		}
		ft_putstr_fd("0x", 1);
		while (-1 + list->prec-- >= (int)ft_strlen(list->res))
		{
			i++;
			ft_putchar_fd('0', 1);
		}
		ft_putstr_fd(list->res, 1);
		return (i + (int)ft_strlen(list->res));
	}
	return ((int)ft_strlen(list->res) + condition_p1(list, i));
}
