/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:02 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/24 10:42:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

void			ft_dlstdel_elem(t_dlist *elem)
{
	char	*tmp;
	size_t	size;

	tmp = (char *)elem->content;
	size = elem->size;
	while (size--)
		*tmp++ = 0;
	elem->size = 0;
	ft_memdel(&elem->content);
	ft_memdel((void **)&elem);
}
