/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_delelem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:17:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/16 20:20:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void			ft_buff_delelem(void *elem)
{
	t_list			*list;
	t_buff			*tmp;
	t_file			*file;
	size_t			i;

	if (elem != 0)
	{
		list = (t_list *)elem;
		tmp = (t_buff *)list->content;
		i = 0;
		file = (t_file *)tmp->buff;
		while (i < tmp->cr)
			ft_strdel(&(file[i++].path));
		ft_memdel((void **)&(tmp->buff));
		ft_memdel((void **)tmp);
		ft_memdel(elem);
	}
}
