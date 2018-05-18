/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:29:53 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_lstreplace_aux(t_list **head, int indice, t_list *old,\
		t_list *new)
{
	t_list			*ret;

	if (indice > 0)
	{
		ret = old->next;
		old->next = new;
		new->next = ret->next;
		ret->next = 0;
	}
	else
	{
		ret = old;
		new->next = ret->next;
		ret->next = 0;
		*head = new;
	}
	return (ret);
}

extern t_list		*ft_lstreplace(t_list **alst, t_list *elem, int indice)
{
	t_list			*tmp;
	int				i;

	if (*alst)
	{
		tmp = *alst;
		i = 0;
		while (++i < indice && tmp->next != 0)
			tmp = tmp->next;
		return (ft_lstreplace_aux(alst, indice, tmp, elem));
	}
	else
		*alst = elem;
	return (0);
}
