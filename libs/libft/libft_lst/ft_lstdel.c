/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:29:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/21 17:16:28 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *elem, size_t size))
{
	if (*alst)
	{
		ft_lstdel(&((*alst)->next), del);
		del((void *)(*alst)->content, (*alst)->size);
		ft_memdel((void **)alst);
	}
}
