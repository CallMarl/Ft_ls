/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:35:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:27:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dlist		*ft_dlstreplace_aux(t_dlist **head, int indice, \
		t_dlist *old, t_dlist *new)
{
	t_dlist			*ret;

	if (indice > 0)
	{
		ret = old->next;
		old->next = new;
		new->next = ret->next;
		ret->next = 0;
	}
	else
	{
		ret = old;
		new->next = ret->next;
		ret->next = 0;
		*head = new;
	}
	return (ret);
}

extern t_dlist		*ft_dlstreplace(t_dlist **alst, t_dlist *elem, int indice)
{
	t_dlist			*tmp;
	int				i;

	if (*alst)
	{
		tmp = *alst;
		i = 0;
		while (++i < indice && tmp->next != 0)
			tmp = tmp->next;
		return (ft_dlstreplace_aux(alst, indice, tmp, elem));
	}
	else
		*alst = elem;
	return (0);
}
