/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:53:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 18:02:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insert une copie de elem dans le buff à un emplacement libre, si le buffeur
** est plein la fonction retourn zero.
*/

extern int			ft_buffadd(t_buff *buff, const void *elem)
{
	if (buff == 0)
		return (-1);
	if (buff->cr >= buff->b_size)
		return (0);
	ft_memcpy(&(((char *)buff->buff)[buff->cr * buff->e_size]), \
			elem, buff->e_size);
	buff->cr++;
	return (1);
}
