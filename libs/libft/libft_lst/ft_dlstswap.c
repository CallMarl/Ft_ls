/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:39:25 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 13:13:32 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dlstswap_aux(t_dlist **head, int indice, t_dlist *elem)
{
	t_dlist		*swp;
	t_dlist		*cur;

	if (elem->next == 0)
		return (0);
	cur = elem;
	if (cur->next == 0)
		indice = 0;
	swp = cur;
	cur = cur->next;
	swp->next = cur->next;
	cur->next = swp;
	if (indice == 0)
	{
		*head = cur;
		if (swp->next != 0)
			swp->next->prev = swp;
	}
	if (swp->prev != 0)
		swp->prev->next = cur;
	cur->prev = swp->prev;
	swp->prev = cur;
	return (1);
}

extern int		ft_dlstswap(t_dlist **alst, int indice)
{
	t_dlist		*tmp;
	int			i;

	if (!(*alst))
		return (0);
	tmp = *alst;
	i = 0;
	while (++i < indice && tmp->next != 0)
	{
		if (tmp->next->next != 0)
		{
			if (tmp->next->next->next != 0)
				tmp = tmp->next;
			else
				break ;
		}
		else
			break ;
	}
	if (indice < 1)
		return (ft_dlstswap_aux(alst, 0, tmp));
	else
		return (ft_dlstswap_aux(alst, i, tmp->next));
}
