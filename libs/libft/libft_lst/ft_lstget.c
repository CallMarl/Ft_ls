/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:39:00 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:28:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstget(t_list *alst, t_content *content, int indice)
{
	t_list			*tmp;
	int				i;

	if (!(alst))
		return (0);
	i = 0;
	tmp = alst;
	while (i++ < indice && tmp->next != 0)
		tmp = tmp->next;
	if (!(content->content = (void *)ft_memalloc(sizeof(char) * tmp->size)))
		return (0);
	content->content = ft_memcpy(content->content, tmp->content, tmp->size);
	content->size = tmp->size;
	return (1);
}
