/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:44:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:53 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstpushb(t_dlist **alst, t_dlist *new_one)
{
	t_dlist		*last;

	if (*alst)
	{
		last = *alst;
		while (last->next != 0)
			last = last->next;
		last->next = new_one;
		new_one->prev = last;
	}
	else
		*alst = new_one;
}
