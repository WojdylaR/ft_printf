/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cond_3_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:27:22 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/12 23:31:26 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		condition_33(t_arg *list, int *j)
{
	int i;

	i = 0;
	if (ft_strchr("id", list->type) && list->res[0] == '-')
	{
		list->prec++;
		ft_putchar_fd('-', 1);
	}
	while (list->prec-- > (int)ft_strlen(list->res) && list->type != '%')
	{
		i++;
		ft_putchar_fd('0', 1);
		*j = *j - 1;
	}
	return (i);
}

int		condition_34(int j, t_arg *list)
{
	int i;

	i = 0;
	while (j-- > (int)ft_strlen(list->res))
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	return (i);
}

int		condition_3(t_arg *list, const char *str)
{
	int j;
	int i;
	int k;
	int m;

	k = list->flag;
	m = list->prec;
	list->prec = list->prec < 0 ? (int)ft_strlen(list->res) : list->prec;
	list->flag = list->flag > 0 ? -list->flag : list->flag;
	i = 0;
	list->type == 's' && check_point(str) == 1 ? new_res(list) : 1;
	j = list->prec >= -list->flag ? list->prec : -list->flag;
	i = condition_33(list, &j);
	if ((ft_strchr("idxXu", list->type) && list->res[0] == '0') &&
			check_point(str) == 1 && k <= 0 && m <= 0)
	{
		i--;
		j++;
	}
	else
		list->res[0] == '-' && list->type != 'c' ?
			ft_putstr_fd(list->res + 1, 1) : ft_putstr_fd(list->res, 1);
	return (i + (int)ft_strlen(list->res) + condition_34(j, list));
}

int		condition_44(t_arg *list, int j, int x)
{
	int i;

	i = 0;
	while (list->blanck-- > list->prec && x-- > (int)ft_strlen(list->res))
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	if (ft_strchr("id", list->type) && list->res[0] == '-')
	{
		j < list->prec ? x++ : x;
		ft_putchar_fd('-', 1);
	}
	while (x-- > (int)ft_strlen(list->res) && list->type != '%')
	{
		i++;
		ft_putchar_fd('0', 1);
	}
	return (i);
}

int		condition_4(t_arg *list, int x)
{
	int i;
	int j;

	j = list->blanck;
	i = 0;
	list->prec == 2 && ft_strlen(list->res) == 2 && list->res[0] == '-' &&
		list->blanck == 2 ? x++ : 1;
	ft_strchr("id", list->type) && list->res[0] == '-' ?
		list->blanck-- : list->blanck;
	if (list->type == 's')
		new_res(list);
	else
		i = i + condition_44(list, j, x);
	list->res[0] == '-' ? ft_putstr_fd(list->res + 1, 1)
		: ft_putstr_fd(list->res, 1);
	return (i + (int)ft_strlen(list->res));
}
