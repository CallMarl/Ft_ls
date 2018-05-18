/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:41:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 18:03:15 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rlstrot_pos(t_rot *rot, int indice, void (*f)(t_dlist *elem))
{
	t_dlist		*tmp;
	size_t		size;

	tmp = rot->head;
	size = 0;
	if ((size_t)indice > rot->size)
		size = (size_t)(indice % rot->size);
	if (size == 0)
		size = rot->size;
	while (size-- > 0)
	{
		f(tmp);
		tmp = tmp->next;
	}
}

static void		ft_rlstrot_neg(t_rot *rot, int indice, void (*f)(t_dlist *elem))
{
	t_dlist		*tmp;
	size_t		size;

	tmp = rot->head;
	size = 0;
	if ((size_t)(-indice) < rot->size)
		size = (size_t)((-indice) % rot->size);
	if (size == 0)
		size = rot->size;
	while (size-- > 0)
	{
		tmp = tmp->prev;
		f(tmp);
	}
}

extern void		ft_rlstiter(t_rot *rot, int indice, void (*f)(t_dlist *elem))
{
	if (indice >= 0)
		ft_rlstrot_pos(rot, indice, f);
	else
		ft_rlstrot_neg(rot, indice, f);
}
