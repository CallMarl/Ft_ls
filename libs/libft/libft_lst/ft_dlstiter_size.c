/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:39:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void		ft_dlstiter_size(t_dlist *lst, size_t size, \
		void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	if (lst)
	{
		tmp = lst;
		while (size-- > 0 && tmp != 0)
		{
			f(tmp);
			tmp = tmp->next;
		}
	}
}
