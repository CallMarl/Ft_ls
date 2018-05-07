/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_rm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:09:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 14:39:03 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Fonction de rappel utilisé par ft_lstdel, afin de libairé le contenu de
** chacun des élement de la list chainé.
*/

extern void			ft_buff_rm(void *elem, size_t size)
{
	ft_buffdel((t_buff *)elem);
	elem = 0;
	(void)size;
}
