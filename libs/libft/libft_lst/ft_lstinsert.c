/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:13:51 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:28:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstinsert(t_list **alst, t_list *elem, int indice)
{
	t_list		*tmp;
	int			i;

	if (*alst)
	{
		tmp = *alst;
		i = 0;
		while (++i < indice && tmp->next != 0)
			tmp = tmp->next;
		if (indice > 0)
		{
			elem->next = tmp->next;
			tmp->next = elem;
		}
		else
		{
			elem->next = tmp;
			*alst = elem;
		}
	}
	else
		*alst = elem;
}
