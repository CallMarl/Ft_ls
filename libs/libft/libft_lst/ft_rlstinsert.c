/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:26:44 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 18:03:47 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static t_dlist		*ft_rlstgetelem_pos(t_rot rot, int indice)
{
	t_dlist			*elem;
	size_t			size;

	elem = rot.head;
	size = indice % rot.size;
	while (size-- > 0)
		elem = elem->next;
	return (elem);
}

static t_dlist		*ft_rlstgetelem_neg(t_rot rot, int indice)
{
	t_dlist			*elem;
	size_t			size;

	elem = rot.head;
	size = (-indice) % rot.size;
	while (size-- > 0)
		elem = elem->prev;
	return (elem);
}

extern void			ft_rlstinsert(t_rot *rot, t_dlist *elem, int indice)
{
	t_dlist			*tmp;

	if (rot->head)
	{
		if (indice >= 0)
			tmp = ft_rlstgetelem_pos(*rot, indice);
		else
			tmp = ft_rlstgetelem_neg(*rot, indice);
		if (tmp->prev != 0)
			tmp->prev->next = elem;
		elem->prev = tmp->prev;
		elem->next = tmp;
		tmp->prev = elem;
		if (indice % rot->size == 0 && (indice > (int)rot->size || indice == 0))
			rot->head = elem;
		(rot->size)++;
	}
	else
	{
		rot->head = elem;
		elem->next = elem;
		elem->prev = elem;
		(rot->size)++;
	}
}
