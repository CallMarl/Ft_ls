/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_setinfo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:04:00 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 16:15:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern void			ft_buffer_setinfo(t_nbuff *nbuffer, t_ninfo ninfo)
{
	nbuffer->ninfo[nbuffer->cur].n_type = ninfo.n_type;
	nbuffer->ninfo[nbuffer->cur].n_mode = ninfo.n_mode;
	nbuffer->ninfo[nbuffer->cur].n_nblink = ninfo.n_nblink;
	nbuffer->ninfo[nbuffer->cur].n_uid = ninfo.n_uid;
	nbuffer->ninfo[nbuffer->cur].n_gid = ninfo.n_gid;
	nbuffer->ninfo[nbuffer->cur].n_size = ninfo.n_size;
	nbuffer->ninfo[nbuffer->cur].n_mtime = ninfo.n_mtime;
	nbuffer->ninfo[nbuffer->cur].n_name = ninfo.n_name;
	(nbuffer->cur++);
}
