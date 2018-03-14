/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:45:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/14 17:55:09 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"



extern int		ft_buffer_initarr(DIR *nd, char *bpath, t_nbuff *nbuffer)
{
	t_ninfo			ninfo;

	ft_node_getinfo(nd, bpath, &ninfo);
	if (!(nbuffer->ninfo = (t_ninfo *)ft_memalloc(sizeof(t_ninfo) * ninfo.n_nblink * 4)))
		return (0);
	nbuffer->cur = 0;
	nbuffer->size = ninfo.n_nblink;
	nbuffer->path = bpath;
	ft_buffer_setinfo(nbuffer, &ninfo);
	return (1);
}
