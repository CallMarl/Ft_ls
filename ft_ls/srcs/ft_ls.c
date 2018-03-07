/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:04:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/07 18:31:49 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>

#include "libft.h"
#include "ft_ls.h"

int				ft_dir_iter(char *bpath, char opt, t_param *param)
{
	DIR				*nd;
	t_nbuff			*nbuffer;

	if (!(nd = opendir(path)))
		return (-1);
	if (!(nbuffer = ft_buffer_init(nd, bpath, nbuffer)))
		return (-1);
	while ((ndetail = ft_readdir(nd)) != 0)
	{

	}
	if (opt == 1)
		ft_dir_iter()...;
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
			ft_ls_launch(path_list.path[path_list.cur], param);
			(path_list.cur)++
		}
	}
	return (0);
}
