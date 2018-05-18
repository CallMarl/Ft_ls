/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:35:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/11 14:09:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** Initialise un buffer du nombre d'élément nb dont la taille est de
** size_t (*size)(void).
*/

extern int			ft_buffinit(t_buff *buff, size_t nb, size_t (*size)(void))
{
	size_t			e_size;

	e_size = size();
	if (!(buff->buff = ft_memalloc(sizeof(char) * (e_size * nb))))
		return (0);
	buff->b_size = nb;
	buff->e_size = e_size;
	buff->cr = 0;
	return (1);
}
