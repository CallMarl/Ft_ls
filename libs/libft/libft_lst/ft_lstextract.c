/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:39:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:28:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstextract(t_list **alst, int indice)
{
	t_list		*tmp;
	t_list		*ret;
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
	ret->next = 0;
	return (ret);
}
