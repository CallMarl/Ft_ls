/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:04:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 19:03:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"

static void			ft_dir_nextiter(char *bpath, char *opt, t_param *param, \
		t_nbuffer *nbuffer)
{
	size_t			i;
	char			*new_bpath;

	i = 2;
	while (i < nbuffer.size)
	{
		if (nbuffer->ninfo[i].ntype == 4)
		{
			new_bpath = ft_strattach(bpath, nbuffer->ninfo[i].name, "/");
			ft_strdel(bpath);
			ft_diriter(new_bpath, opt, param);
		}
		i++;
	}
	ft_memdel((void **)&(nbuffer->ninfo))
	ft_strdel(bpath);
}

static int			ft_dir_iter(char *bpath, char opt, t_param *param)
{
	DIR				*nd;
	t_nbuff			nbuffer;

	if (!(nd = opendir(bpath)))
		return (-1);
	if (!(nbuffer = ft_buffer_initarr(nd, bpath, &nbuffer)))
		return (-1);
	while ((ft_node_getinfo(nd, bpath, ninfo)) != 0)
		ft_buffer_setinfo(nbuffer, ninfo);
	ft_display_buffer(buffer, bpath, param);
	if (opt == 1)
		ft_dir_nextiter(bpath, opt, param, &nbuffer);
	return (0);
}

static int			ft_ls_launch(char *bpath, t_param *param)
{
	char			opt;

	opt = (ft_param_get(param, 'R') == TRUE) ? 1 : 0;
	ft_dir_iter(nd, ".", opt);
}

extern int			ft_ls(int argc, char **argv)
{
	t_param			*param;
	int				cur;
	t_path			path_list;

	param = 0;
	if ((cur = ft_param_parse(argc, argv, &param)) == -1)
		return (-1);
	ft_path_init(argc, argv, cur, &path_list);
	if (path_list.size == 0)
		ft_ls_launch(".", param);
	else
	{
		while (path_list.cur < path_list.size)
		{
			ft_ls_launch(ft_strdup(path_list.path[path_list.cur]), \
					param);
			(path_list.cur)++
		}
	}
	return (0);
}
