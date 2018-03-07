/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_setinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:25:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/07 19:58:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stats.h>
#include <time.h>
#include <dirent.h>
#include "ft_ls.h"

void		ft_node_setinfo(t_dirent *ndetail, t_stat *nextra, t_ninfo *ninfo)
{
	ninfo->n_type = ndetail->d_type;
	ninfo->n_mode = nexta->st_mode;
	ninfo->n_nblink = nextra->st_link;
	ninfo->n_uid = nextra->st_uid;
	ninfo->n_gid = nextra->st_gid;
	ninfo->n_size = nextra->st_size;
	ninfo->n_mtime = nextra->st_mtimespec;
	ninfo->n_name = ndetail->d_name;
}
