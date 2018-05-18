/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:51:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/23 12:36:54 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void			ft_lstdel_elem(t_list *elem)
{
	char	*tmp;
	size_t	size;

	tmp = elem->content;
	size = elem->size;
	while (size--)
		*tmp++ = 0;
	elem->size = 0;
	ft_memdel(&elem->content);
	ft_memdel((void **)&elem);
}
