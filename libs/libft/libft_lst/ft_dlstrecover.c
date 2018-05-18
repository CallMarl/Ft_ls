/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrecover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:32:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:53:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstrecover(t_dlist *alst, int indice)
{
	t_dlist		*tmp;
	t_dlist		*cpy;
	int			i;

	if (alst == 0)
		return (0);
	tmp = alst;
	i = 0;
	while (i++ < indice && tmp->next != 0)
		tmp = tmp->next;
	if (!(cpy = ft_dlstnew(tmp->content, tmp->size)))
		return (0);
	return (cpy);
}
