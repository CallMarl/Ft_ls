/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:40:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/25 16:53:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list **elem)
{
	t_list		*last;

	if (elem && *elem)
	{
		last = *elem;
		while (last->next != 0)
			last = last->next;
		return (last);
	}
	return (0);
}
