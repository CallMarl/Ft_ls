/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:17:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:51:38 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstpushf(t_dlist **alst, t_dlist *new_one)
{
	if (*alst)
	{
		(*alst)->prev = new_one;
		new_one->next = *alst;
	}
	*alst = new_one;
}
