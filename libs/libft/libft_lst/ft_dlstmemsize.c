/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmemsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:04:25 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:33 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t		ft_dlstmemsize(t_dlist *lst)
{
	size_t	size;
	t_dlist	*tmp;

	size = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			size += tmp->size;
			tmp = tmp->next;
		}
	}
	return (size);
}
