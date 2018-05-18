/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:30:19 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:28:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*tmp;

	cpy = 0;
	if (lst)
	{
		cpy = ft_lstmap(lst->next, f);
		if ((tmp = f(lst)) == 0)
			return (0);
		if (cpy)
			ft_lstpushf(&cpy, tmp);
		else
		{
			if ((cpy = ft_lstnew(tmp->content, tmp->size)) == 0)
				return (0);
		}
	}
	return (cpy);
}
