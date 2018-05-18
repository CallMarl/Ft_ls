/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:42:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/30 16:53:16 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int		ft_dlstpush(t_dlist **alst, void *data, size_t content_size, \
		void (*f)(t_dlist **list, t_dlist *elem))
{
	t_dlist *elem;

	if (*alst == 0)
	{
		if (!(*alst = ft_dlstnew(data, content_size)))
			return (0);
	}
	else
	{
		if (!(elem = ft_dlstnew(data, content_size)))
			return (0);
		f(alst, elem);
	}
	return (1);
}
