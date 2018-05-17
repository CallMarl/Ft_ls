/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:59:00 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:08:59 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Retourne un pointeur t_file qui pointe sur l'élément i du premier élément
** t_buff de la liste de buffeur (chainé).
*/

extern t_buff		*ft_buff_get(t_list *buff)
{
	return (((t_buff *)buff->content));
}
