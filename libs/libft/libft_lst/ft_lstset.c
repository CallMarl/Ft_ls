/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:53:38 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:54:06 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstset(t_list *alst, t_content content, int indice)
{
	t_list		*tmp;
	int			i;

	if (!(alst))
		return (0);
	i = 0;
	tmp = alst;
	while (i++ < indice && tmp->next != 0)
		tmp = tmp->next;
	if (tmp->content != 0)
		ft_memdel_size(tmp->content, tmp->size);
	if (!(tmp->content = ft_memalloc(sizeof(char) * content.size)))
		return (0);
	tmp->content = ft_memcpy(tmp->content, content.content, content.size);
	tmp->size = content.size;
	return (1);
}
