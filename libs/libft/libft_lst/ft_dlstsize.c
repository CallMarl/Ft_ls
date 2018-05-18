/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:25:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:27:42 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dlstsize(t_dlist *begin_list)
{
	if (begin_list)
		return (1 + ft_dlstsize(begin_list->next));
	return (0);
}
