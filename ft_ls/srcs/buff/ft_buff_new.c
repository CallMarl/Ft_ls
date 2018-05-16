/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:12:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/16 18:45:59 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Fonction de rappel, demandé par la libft et la fonction ft_buffinit, 
** afin de définir la taille d'un élément du buffer.
*/

static size_t		ft_e_size(void)
{
	return ((size_t)sizeof(t_file));
}


/*
** Insertion d'un nouveau maillon t_list en tete de list et allocation
** du buffer. Ou nouveaux buffer.
*/

extern int			ft_buff_new(t_list **list, size_t b_size)
{
	t_buff			buff;

	if (!ft_lstpush(list, (void *)&buff, sizeof(t_buff), &ft_lstpushf))
		return (-1);
	if (!(ft_buffinit((t_buff *)(*list)->content, b_size, &ft_e_size)))
		return (-1);
	return (1);
}
