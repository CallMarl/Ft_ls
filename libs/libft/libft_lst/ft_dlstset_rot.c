/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstset_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:48:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/30 21:33:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void			ft_dlstset_rot(t_dlist **alst, t_rot *rot)
{
	size_t		size;
	t_dlist		*last;

	if (*alst)
	{
		last = *alst;
		size = 0;
		while (last->next != 0)
		{
			last = last->next;
			size++;
		}
		size++;
		last->next = *alst;
		(*alst)->prev = last;
		rot->head = *alst;
		rot->size = size;
	}
}
