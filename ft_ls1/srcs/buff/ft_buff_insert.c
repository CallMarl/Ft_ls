/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:33:19 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 17:26:31 by pprikazs         ###   ########.fr       */
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
** du buffer.
*/

static int			ft_buff_new(t_list **list, size_t b_size)
{
	t_buff			buff;

	if (!ft_lstpush(list, (void *)&buff, sizeof(t_buff), &ft_lstpushf))
		return (-1);
	return (ft_buffinit((t_buff *)(*list)->content, b_size, &ft_e_size));
}

/*
** Fonction d'insertion du buffer si le buffer est trop petit ou pas encore
** initialise, créer un nouvelle élément t_list, sinon ajoute directement
** au buffer l'element
*/

extern int			ft_buff_insert(t_list **list, t_file *elem, size_t b_size)
{
	int				ret;
	int				i;

	ret = 1;
	if (list == 0 || *list == 0)
		ret = ft_buff_new(list, b_size);
	i = 0;
	while (ret >= 0 && (ret = ft_buffadd((t_buff *)(*list)->content, (void *)elem)) <= 0 \
			&& i < 1)
	{
		if (ret == 0)
			ret = ft_buff_new(list, b_size);
		else
			return (ret);
		i++;
	}
	return (ret);
}
