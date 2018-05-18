/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstissort_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:03:16 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:49:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

extern int				ft_dlstissort_d(t_dlist *alst, size_t size)
{
	t_dlist				*tmp;

	if (!alst)
		return (-1);
	tmp = alst;
	while (--size)
	{
		if ((int)(*((int *)tmp->content)) < (int)(*((int *)tmp->next->content)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
