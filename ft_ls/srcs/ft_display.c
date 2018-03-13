/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:40:13 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 19:03:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#define RC ft_putchar('\n')

extern void			ft_display_ninfo(t_ninfo ninfo)
{
	ft_putnbr(ninfo.n_type);RC;
	ft_putnbr(ninfo.n_mode);RC;
	ft_putnbr(ninfo.n_nblink);RC;
	ft_putstr(ninfo.n_uid);RC;
	ft_putstr(ninfo.n_gid);RC;
	ft_putnbr(ninfo.n_size);RC;
	ft_putnbr(ninfo.n_time);RC;
	ft_putstr(ninfo.n_name);RC;
	RC;RC;
}

extern void			ft_display_nbuffer(t_nbuffer nbuffer)
{
	size_t			i;

	if (nbuffer.ninfo != 0)
	{
		i = 0
		while (i < nbuffer.size)
			ft_display_ninfo(nbuffer.ninfo[i++]);
	}
}
