/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:03:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:30:16 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lstswap_aux(t_list **head, int indice, t_list *elem)
{
	t_list		*swp;
	t_list		*cur;

	cur = 0;
	if (elem->next == 0)
		return (0);
	if (indice > 0)
		cur = elem->next;
	if (cur == 0 || cur->next == 0)
	{
		cur = elem;
		indice = 0;
	}
	swp = cur;
	cur = cur->next;
	swp->next = cur->next;
	cur->next = swp;
	if (indice == 0)
		*head = cur;
	else
		elem->next = cur;
	return (1);
}

extern int		ft_lstswap(t_list **alst, int indice)
{
	t_list		*tmp;
	int			i;

	if (!(*alst))
		return (0);
	tmp = *alst;
	i = 0;
	while (++i < indice && tmp->next != 0)
	{
		if (tmp->next->next != 0)
		{
			if (tmp->next->next->next != 0)
				tmp = tmp->next;
			else
				break ;
		}
		else
			break ;
	}
	if (indice == 0)
		i = 0;
	return (ft_lstswap_aux(alst, i, tmp));
}
