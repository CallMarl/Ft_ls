/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:45:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 16:15:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"



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
	return (nbuffer);
}
