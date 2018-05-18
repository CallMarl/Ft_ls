/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:00:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 12:47:15 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void			ft_rlstrotate_pos(t_rot *rot, int indice)
{
	t_dlist			*head;
	size_t			size;

	head = rot->head;
	size = (size_t)(indice % rot->size);
	while (size-- > 0)
		head = head->next;
	rot->head = head;
}

static void			ft_rlstrotate_neg(t_rot *rot, int indice)
{
	t_dlist			*head;
	size_t			size;

	head = rot->head;
	size = (size_t)((-indice) % rot->size);
	while (size-- > 0)
		head = head->prev;
	rot->head = head;
}

extern void			ft_rlstrotate(t_rot *rot, int indice)
{
	if (indice > 0)
		ft_rlstrotate_pos(rot, indice);
	else
		ft_rlstrotate_neg(rot, indice);
}
