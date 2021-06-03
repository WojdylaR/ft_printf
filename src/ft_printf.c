/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:36:35 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:53:02 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_point(const char *str)
{
	int i;

	i = 1;
	while (!(ft_strchr("cspdiuxX%", str[i])))
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	new_res(t_arg *list)
{
	char *temp;

	list->prec = list->prec < 0 ? (int)ft_strlen(list->res) : list->prec;
	temp = ft_strdup(list->res);
	free(list->res);
	if (list->type == 'p')
		list->res = ft_strdup("0x");
	else
		list->res = ft_substr(temp, 0, list->prec);
	free(temp);
	list->prec = list->prec > (int)ft_strlen(list->res) ?
		(int)ft_strlen(list->res) : list->prec;
}

int		ft_size_nbr(int x)
{
	int i;

	i = 0;
	while (x % 10 > 10)
	{
		i++;
		x = x / 10;
	}
	return (i);
}

int		ft_print(const char *str, t_arg *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
		{
			j = j + ft_putflag(list, str + i);
			if (list->next != 0)
				list = list->next;
			i++;
			while (!(ft_strchr("csdiuxXp%", str[i])))
				i++;
			i++;
		}
		if (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
			j++;
		}
	}
	return (j);
}

int		ft_printf(const char *str, ...)
{
	t_arg	*list;
	va_list list_arg;
	int		d;

	if (!(list = malloc(sizeof(t_arg))))
		return (0);
	list->next = 0;
	va_start(list_arg, str);
	new_list(list, str, list_arg);
	d = ft_print(str, list);
	ft_free_list(list);
	return (d);
}
