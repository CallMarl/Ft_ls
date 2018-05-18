/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:30:19 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:00 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstinsert(t_dlist **alst, t_dlist *elem, int indice)
{
	t_dlist		*tmp;
	int			i;

	if (*alst)
	{
		tmp = *alst;
		i = 0;
		while (++i < indice && tmp->next != 0)
			tmp = tmp->next;
		if (indice > 0)
		{
			elem->next = tmp->next;
			elem->prev = tmp;
			tmp->next = elem;
		}
		else
		{
			elem->next = tmp;
			*alst = elem;
		}
		if (elem->next != 0)
			elem->next->prev = elem;
	}
	else
		*alst = elem;
}
