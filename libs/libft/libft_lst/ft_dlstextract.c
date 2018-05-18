/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstextract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:23:10 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:25:45 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstextract(t_dlist **alst, int indice)
{
	t_dlist		*tmp;
	t_dlist		*ret;
	int			i;

	if (!(*alst))
		return (0);
	tmp = *alst;
	i = 0;
	while (++i < indice && tmp->next != 0)
		tmp = tmp->next;
	if (indice == 0)
	{
		ret = tmp;
		*alst = tmp->next;
	}
	else
	{
		ret = tmp->next;
		tmp->next = ret->next;
	}
	if (tmp->next != 0)
		tmp->next->prev = ret->prev;
	ret->next = 0;
	ret->prev = 0;
	return (ret);
}
