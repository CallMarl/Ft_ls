/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:04:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 16:50:01 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"

static int			ft_dir_nextiter(char *bpath, char opt, t_param *param, \
		t_nbuff *nbuffer)
{
	size_t			i;
	char			*new_bpath;

	i = 2;
	while (i < nbuffer->size)
	{
		if (nbuffer->ninfo[i].n_type == 4)
		{
			new_bpath = ft_strattach(bpath, nbuffer->ninfo[i].n_name, "/");
			if (!(ft_ls_launch(new_bpath, opt, param)))
			{
				ft_memdel((void **)&(nbuffer->ninfo));
				ft_strdel(&bpath);
				return (0);
			}
		}
		i++;
	}
	ft_memdel((void **)&(nbuffer->ninfo));
	ft_strdel(&bpath);
	return (1);
}

static int			ft_dir_iter(DIR *nd, char *bpath, char opt, t_param *param)
{
	t_nbuff			nbuffer;
	t_ninfo			ninfo;

	if (!(ft_buffer_initarr(nd, bpath, &nbuffer)))
		return (0);
	while ((ft_node_getinfo(nd, bpath, &ninfo)) != 0)
	{
		ft_buffer_setinfo(&nbuffer, &ninfo);
	}
	ft_display_nbuffer(nbuffer);
	if (opt == 1)
	{
		if (!(ft_dir_nextiter(bpath, opt, param, &nbuffer)))
			return (0);
	}
	return (1);
}

extern int			ft_ls_launch(char *bpath, char opt, t_param *param)
{
	DIR				*nd;
	int				ret;

	nd = 0;
	if (!(nd = opendir(bpath)))
		return (0);
	ret = 1;
	if (!(ft_dir_iter(nd, bpath, opt, param)))
		ret = 0;
	closedir(nd);
	return (ret);
}

static int			ft_ls_checkparam(char *bpath, t_param *param)
{
	char			opt;

	opt = (ft_param_get(param, 'R') == TRUE) ? 1 : 0;
	if (!(ft_ls_launch(bpath, opt,  param)))
		return (0);
	return (1);
}

extern int			ft_ls(int argc, char **argv)
{
	t_param			*param;
	int				cur;
	char			*bpath;
	t_path			path_list;

	param = 0;
	if ((cur = ft_param_parse(argc, argv, &param)) == -1)
		return (0);
	ft_path_init(argc, argv, cur, &path_list);
	if (path_list.size == 0)
		ft_ls_checkparam(ft_strdup("."), param);
	else
	{
		while (path_list.cur < path_list.size)
		{
			bpath = ft_strdup(path_list.path[path_list.cur]);
			if (!(ft_ls_checkparam(bpath, param)))
				return (0);
			(path_list.cur)++;
		}
	}
	return (1);
}
