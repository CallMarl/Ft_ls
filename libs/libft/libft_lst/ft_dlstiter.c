/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:57:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:07 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp != 0)
		{
			f(tmp);
			tmp = tmp->next;
		}
	}
}
