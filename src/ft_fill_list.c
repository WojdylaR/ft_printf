/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:36:17 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/07/01 17:52:32 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_flag(const char *str, va_list list_arg)
{
	int i;

	i = 0;
	if (str[i + 1] == '*' || str[i] == '*')
	{
		if (str[i] == '-')
			return (-va_arg(list_arg, int));
		return (va_arg(list_arg, int));
	}
	if ((ft_isdigit(str[i]) || str[i] == '-') && str[i + 1] != '*')
	{
		while (str[i + 1] == '-')
			i++;
		ft_atoi(str + i);
		return (ft_atoi(str + i));
	}
	return (0);
}

void		*ft_fill_flag(t_arg *list, const char *str, va_list list_arg)
{
	int j;

	j = 0;
	list->prec = '\0';
	list->flag = '\0';
	list->blanck = '\0';
	if (str[j] == '0' && ft_strchr("0123456789*", str[j + 1]))
		list->blanck = ft_flag(str + 1, list_arg);
	else if (ft_strchr("0123456789-*", str[j]))
		list->flag = ft_flag(str, list_arg);
	while (ft_isdigit(str[j]) == 1 || str[j] == '-' || str[j] == '*')
		j++;
	if (str[j] == '.')
		list->prec = ft_flag(str + j + 1, list_arg);
	list->flag = list->blanck < 0 ? list->blanck : list->flag;
	return (0);
}

int			ft_lstnew_type(t_arg *list, const char *str)
{
	int		i;
	t_arg	*new;

	if (!(new = malloc(sizeof(t_arg))))
		return (0);
	list->next = new;
	new->next = 0;
	i = 1;
	while (ft_strchr("-0.*123456789", str[i]))
		i++;
	if (ft_strchr("cspdiuxX%", str[i]))
		list->type = str[i];
	else
		list->type = 'N';
	return (1);
}

void		ft_fill_arg(t_arg *list, const char *str, va_list list_arg)
{
	ft_fill_flag(list, str + 1, list_arg);
	list->type == 'N' ? list->res = ft_strdup("") : NULL;
	if (list->type == '%')
		list->res = ft_fill_char('%');
	if (list->type == 's')
		list->res = ft_test_s(list, list_arg, str);
	if (list->type == 'd' || list->type == 'i')
		list->res = ft_itoa(va_arg(list_arg, int));
	if (list->type == 'c')
		list->res = ft_fill_char(va_arg(list_arg, unsigned int));
	if (list->type == 'u')
		list->res = ft_utoa(va_arg(list_arg, unsigned int));
	if (list->type == 'x')
		list->res =
			ft_itoa_base(va_arg(list_arg, unsigned int), "0123456789abcdef");
	if (list->type == 'X')
		list->res =
			ft_itoa_base(va_arg(list_arg, unsigned int), "0123456789ABCDEF");
	if (list->type == 'p')
		list->res = ft_put_address(va_arg(list_arg, unsigned long));
	if (list->res == NULL)
	{
		free(list->res);
		list->res = ft_strdup("(null)");
	}
}

int			new_list(t_arg *list, const char *str, va_list list_arg)
{
	int i;

	i = 0;
	list->next = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_lstnew_type(list, str + i);
			ft_fill_arg(list, str + i, list_arg);
			if (list->type == '%')
			{
				list->prec = 0;
				i++;
				while (str[i] != '%')
					i++;
			}
			list = list->next;
		}
		i++;
	}
	return (1);
}
