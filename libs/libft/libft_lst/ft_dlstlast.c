/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:43:14 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:26:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstlast(t_dlist **alst)
{
	t_dlist		*last;

	if (*alst)
	{
		last = *alst;
		while (last->next != 0)
			last = last->next;
		return (last);
	}
	return (0);
}
