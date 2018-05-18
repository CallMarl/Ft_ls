/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffextend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:49:02 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 18:03:32 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Fonction utilisé pour etendre le buffer, il y seulement besoin de passer un
** buffer en paramettre et le nombre d'élément supplémentaire que l'on souhaite
*/

extern int			ft_buffextend(t_buff *buff, size_t nb)
{
	size_t			new_size;
	void			*new;

	if (buff == 0)
		return (0);
	new_size = (buff->b_size + nb) * buff->e_size;
	if (!(new = ft_memalloc(sizeof(char) * new_size)))
		return (0);
	ft_memcpy(new, buff->buff, buff->b_size * buff->e_size);
	ft_memdel((void **)&(buff->buff));
	buff->buff = new;
	buff->b_size += nb;
	return (1);
}
