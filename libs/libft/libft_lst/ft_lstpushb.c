/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:46:32 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:29:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpushb(t_list **alst, t_list *new_one)
{
	t_list		*last;

	if (*alst)
	{
		last = *alst;
		while (last->next != 0)
			last = last->next;
		last->next = new_one;
	}
	else
		*alst = new_one;
}
