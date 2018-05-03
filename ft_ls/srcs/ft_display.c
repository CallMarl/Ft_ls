/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:40:13 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 16:15:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <time.h>
#include "ft_ls.h"
#include "libft.h"
#define RC ft_putchar('\n')
#define SP ft_putchar(' ')

/*
static char			ft_lstime(t_tm date, char *buff)
{
}
*/

extern void			ft_display_ninfo(t_ninfo ninfo)
{
//	ft_putnbr(ninfo.n_type);RC;
//	ft_putnbr(ninfo.n_mode);RC;
//	ft_putnbr(ninfo.n_nblink);RC;
//	ft_putnbr(ninfo.n_uid);RC;
//	ft_putnbr(ninfo.n_gid);RC;
//	ft_putnbr(ninfo.n_size);RC;

//	t_tm	date;

//	ft_localtime_r(&(ninfo.n_mtime.tv_sec), &date);RC;
//	ft_putnbr(ninfo.n_mtime.tv_sec);RC;
	ft_putstr(ninfo.n_name);RC;
}

extern void			ft_display_nbuffer(t_nbuff nbuffer)
{
	size_t			i;

	if (nbuffer.ninfo != 0)
	{
		i = 0;
		while (i < nbuffer.size)
			ft_display_ninfo(nbuffer.ninfo[i++]);
		RC;
	}
}
