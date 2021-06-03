/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:17:58 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 00:21:29 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*dst;

	if ((*alst) && new && alst)
	{
		dst = *alst;
		if (dst == NULL)
			*alst = new;
		else
		{
			while (dst->next)
				dst = dst->next;
			dst->next = new;
		}
	}
}
