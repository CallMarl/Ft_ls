/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:37:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:53:38 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dlstset(t_dlist *alst, t_content content, int indice)
{
	t_dlist		*tmp;
	int			i;

	if (!(alst))
		return (0);
	i = 0;
	tmp = alst;
	while (i++ < indice && tmp->next != 0)
		tmp = tmp->next;
	if (!(tmp->content = ft_memalloc(sizeof(char) * content.size)))
		return (0);
	if (tmp->content != 0)
		ft_memdel_size(tmp->content, tmp->size);
	tmp->content = ft_memcpy(tmp->content, content.content, content.size);
	tmp->size = content.size;
	return (1);
}
