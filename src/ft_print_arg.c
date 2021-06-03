/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:36:04 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:13:40 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		condition_11(t_arg *list, int x, int i)
{
	if (ft_strchr("id", list->type) && list->res[0] == '-')
		ft_putchar_fd('-', 1);
	while (x-- > (int)ft_strlen(list->res) && list->type != 's')
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	list->res[0] == '-' ? ft_putstr_fd(list->res + 1, 1)
		: ft_putstr_fd(list->res, 1);
	return (i + (int)ft_strlen(list->res));
}

int		condition_1(t_arg *list, int x, const char *str)
{
	int		i;
	int		j;

	i = 0;
	j = list->prec;
	list->prec >= list->flag && list->res[0] == '-' ? x++ : 1;
	list->prec = list->prec > (int)ft_strlen(list->res) ?
		(int)ft_strlen(list->res) : list->prec;
	if (list->type == 's' && check_point(str) == 1)
		new_res(list);
	j = list->type == 's' ? list->prec : j;
	list->res[0] == '-' && ft_strchr("id", list->type ? j++ : 1);
	while (list->flag-- > j && x > (int)ft_strlen(list->res))
	{
		x--;
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (condition_11(list, x, i));
}

int		condition_2(t_arg *list, int x, const char *str)
{
	int i;

	i = 0;
	if ((ft_strchr("idxXu", list->type) && list->res[0] == '0')
			&& check_point(str) == 1)
		x++;
	if (list->type == 's' && check_point(str) == 1)
		new_res(list);
	while (x-- > (int)ft_strlen(list->res))
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	if ((ft_strchr("idxXu", list->type) && list->res[0] == '0')
			&& check_point(str) == 1)
		return (i);
	ft_putstr_fd(list->res, 1);
	return (i + (int)ft_strlen(list->res));
}

int		condition_6(t_arg *list)
{
	int i;

	i = 0;
	list->res[0] == '0' && list->type != 'p' ? list->blanck++ : 1;
	if (list->type == 's')
		return (0);
	while (list->blanck-- > (int)ft_strlen(list->res))
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (list->res[0] == '0' && list->type != 'p' && list->prec == 0)
		return (i);
	ft_putstr_fd(list->res, 1);
	return (i + (int)ft_strlen(list->res));
}

int		ft_putflag(t_arg *list, const char *str)
{
	int	x;
	int i;

	i = 0;
	x = list->prec >= list->blanck ? list->prec : list->blanck;
	x = x >= list->flag ? x : list->flag;
	x = x >= -list->flag ? x : -list->flag;
	if (list->type == 'c' && list->res[0] == 0)
		return (czero(list));
	if (list->type == 'p')
		return (condition_p(list, str));
	if (list->flag == 0 && list->prec == 0 && check_point(str) == 1)
		i = condition_6(list);
	if (list->flag == '\0' && list->prec != '\0')
		i = condition_4(list, x);
	if ((list->flag == 0 && list->prec == '\0' && check_point(str) == 0))
		i = condition_7(list, x, str);
	if (list->flag > 0 && list->prec > 0 && str[1] != '-')
		i = condition_1(list, x, str);
	if (list->flag > 0 && list->prec == '\0' && str[1] != '-')
		i = condition_2(list, x, str);
	if ((list->flag < 0 || (list->flag > 0 && str[1] == '-')) && i == 0)
		i = condition_3(list, str);
	return (i);
}
