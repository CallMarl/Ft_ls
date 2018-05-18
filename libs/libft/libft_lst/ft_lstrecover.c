/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrecover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:01:51 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 18:02:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstrecover(t_list *alst, int indice)
{
	t_list		*tmp;
	t_list		*cpy;
	int			i;

	if (alst == 0)
		return (0);
	tmp = alst;
	i = 0;
	while (i++ < indice && tmp->next != 0)
		tmp = tmp->next;
	if (!(cpy = ft_lstnew(tmp->content, tmp->size)))
		return (0);
	return (cpy);
}
