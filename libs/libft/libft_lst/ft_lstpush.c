/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_ultimate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:27:59 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:29:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstpush(t_list **alst, void *data, size_t content_size, \
		void (*f)(t_list **list, t_list *elem))
{
	t_list		*elem;

	if (*alst == 0)
	{
		if (!(*alst = ft_lstnew(data, content_size)))
			return (0);
	}
	else
	{
		if (!(elem = ft_lstnew(data, content_size)))
			return (0);
		f(alst, elem);
	}
	return (1);
}
