/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:36:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:51:00 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Penser a free tmp
*/

t_dlist		*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*cpy;
	t_dlist	*last;
	t_dlist	*tmp;

	cpy = 0;
	if (lst)
	{
		last = ft_dlstlast(&lst);
		while (last != 0)
		{
			if ((tmp = f(last)) == 0)
				return (0);
			if (cpy)
				ft_dlstpushf(&cpy, tmp);
			else
			{
				if ((cpy = ft_dlstnew(tmp->content, tmp->size)) == 0)
					return (0);
			}
			last = last->prev;
		}
	}
	return (cpy);
}
