/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_getinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:10:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/15 14:39:53 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"

extern int			ft_node_getinfo(DIR *nd, char *bpath, t_ninfo *ninfo)
{
	t_dirent		*ndetail;
	t_stat			nextra;
	char			*path;

	if (!(ndetail = readdir(nd)))
		return (0);
	path = ft_strattach(bpath, ndetail->d_name, "/");
	if(stat(path, &nextra) == -1)
		return (0);
	ft_node_setinfo(ndetail, &nextra, ninfo);
	return (1);
}
