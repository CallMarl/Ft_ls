/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:35:34 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:28:43 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void		ft_lstiter_size(t_list *lst, size_t size, void (*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		while (size-- > 0 && tmp != 0)
		{
			f(tmp);
			tmp = tmp->next;
		}
	}
}
