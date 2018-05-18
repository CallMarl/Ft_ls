/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:33:04 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:27:11 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstremove(t_dlist **alst, int indice)
{
	t_dlist		*tmp;
	t_dlist		*rem;
	int			i;

	if (*alst)
	{
		tmp = *alst;
		i = 0;
		while (++i < indice && tmp->next != 0)
			tmp = tmp->next;
		rem = tmp->next;
		tmp->next = rem->next;
		tmp->next->prev = tmp;
		ft_dlstdel_elem(rem);
	}
}
