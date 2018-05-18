/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_getfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:12:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:22:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Retourne un pointeur t_file qui pointe sur l'élément i du premier élément
** t_buff de la liste de buffeur (chainé).
*/

extern t_file
	*ft_buff_getfile(t_buff *buff, int i)
{
	return (&((t_file *)buff->buff)[i]);
}
