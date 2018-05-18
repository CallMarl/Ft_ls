/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:26:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/30 21:36:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static t_dlist		*ft_rlstgetelem_pos(t_dlist *elem, int indice)
{
	while (indice-- > 0)
		elem = elem->next;
	return (elem);
}

static t_dlist		*ft_rlstgetelem_neg(t_dlist *elem, int indice)
{
	while (indice-- > 0)
		elem = elem->prev;
	return (elem);
}

extern void			ft_rlstremove(t_rot *rot, int indice)
{
	t_dlist		*tmp;
	int			size;

	if (rot->head)
	{
		tmp = rot->head;
		if (indice > 0)
		{
			size = indice % rot->size;
			tmp = ft_rlstgetelem_pos(tmp, size);
		}
		else
		{
			size = -indice % rot->size;
			tmp = ft_rlstgetelem_neg(tmp, size);
		}
		if (tmp->prev != 0)
			tmp->prev->next = tmp->next;
		if (tmp->next != 0)
			tmp->next->prev = tmp->prev;
		if (size == 0)
			rot->head = tmp->next;
		(rot->size)--;
		ft_dlstdel_elem(tmp);
	}
}
