/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:45:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/07 20:00:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"

static void			ft_buffer_setinfo(t_nbuff *nbuffer, t_ninfo ninfo)
{
	nbuffer->ninfo[nbuffer->cur].n_type = ninfo.n_type;
	nbuffer->ninfo[nbuffer->cur].n_mode = ninfo.n_mode;
	nbuffer->ninfo[nbuffer->cur].n_nblink = ninfo.n_nblink;
	nbuffer->ninfo[nbuffer->cur].n_uid = ninfo.n_uid;
	nbuffer->ninfo[nbuffer->cur].n_gid = ninfo.n_gid;
	nbuffer->ninfo[nbuffer->cur].n_size = ninfo.n_size;
	nbuffer->ninfo[nbuffer->cur].n_mtime = ninfo.n_mtime;
	nbuffer->ninfo[nbuffer->cur].n_name = ninfo.n_name;
}

extern t_buffer		*ft_buffer_initarr(DIR *nd, char *bpath, t_nbuff *nbuffer)
{
	t_ninfo			ninfo;

	ft_node_getinfo(nd, bpath, &ninfo);
	if (!(nbuffer->ninfo = (t_ninfo *)ft_memalloc(sizeof(t_info) ninfo.n_nblink)))
		return (0);
	nbuffer->cur = 0;
	nbuffer->size = ninfo.n_nblink;
	nbuffer->path = bpath;
	ft_buffer_setinfo(nbuffer, ninfo);
	return (nbuffer)
}
