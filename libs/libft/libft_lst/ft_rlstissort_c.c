/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstissort_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:58:10 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:54:43 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

extern int				ft_dlstissort_c(t_dlist *alst, size_t size)
{
	t_dlist				*tmp;

	if (!alst)
		return (0);
	tmp = alst;
	while (--size)
	{
		if ((int)(*((int *)tmp->content)) > (int)(*((int *)tmp->next->content)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
