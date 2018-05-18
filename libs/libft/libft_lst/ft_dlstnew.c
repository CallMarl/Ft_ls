/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:40:02 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:42 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_dlist		*ft_dlstnew(const void *content, size_t size)
{
	t_dlist	*lst;

	if ((lst = (t_dlist *)ft_memalloc(sizeof(t_dlist))) == 0)
		return (0);
	if (content)
	{
		lst->content = ft_memalloc(sizeof(unsigned char) * (size));
		if (lst->content)
		{
			ft_memcpy(lst->content, content, size);
			lst->size = size;
		}
	}
	else
	{
		lst->content = 0;
		lst->size = 0;
	}
	lst->next = 0;
	lst->prev = 0;
	return (lst);
}
