/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:22:41 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:16:05 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_list(t_arg *list)
{
	t_arg	*temp;

	if (list->next != 0)
	{
		while (list->next != 0)
		{
			free(list->res);
			temp = list->next;
			free(list);
			list = temp;
		}
		free(list);
	}
	else
		free(list);
}
