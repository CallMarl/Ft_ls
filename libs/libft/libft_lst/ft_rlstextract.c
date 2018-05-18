/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstextract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:26:38 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 18:20:04 by pprikazs         ###   ########.fr       */
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

extern t_dlist		*ft_rlstextract(t_rot *rot, int indice)
{
	t_dlist			*tmp;
	int				size;

	if (!(rot->head))
		return (0);
	size = (indice >= 0) ? indice % rot->size : -indice % rot->size;
	if (indice >= 0)
		tmp = ft_rlstgetelem_pos(*rot, indice);
	else
		tmp = ft_rlstgetelem_neg(*rot, indice);
	if (tmp->prev != 0)
		tmp->prev->next = tmp->next;
	if (tmp->next != 0)
		tmp->next->prev = tmp->prev;
	if (size == 0)
		rot->head = tmp->next;
	if (rot->size == 1)
		rot->head = 0;
	tmp->next = 0;
	tmp->prev = 0;
	(rot->size)--;
	return (tmp);
}
