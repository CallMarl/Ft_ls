/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_noarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:04:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/15 12:02:52 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Dans le cas de récursif rappel de noarg pour chaque dossier
*/

static int			ft_ls_subdir(t_list **buff, int opt_R, int opt_A)
{
	int				ret;
	size_t			i;
	t_buff			*tmp;
	t_file			*file;

	i = 0;
	tmp = (t_buff *)(*buff)->content;
	while (i < tmp->b_size)
	{
		file = ft_buff_getfile(tmp, i);
		if (ft_strcmp(file->name, ".") != 0 && ft_strcmp(file->name, "..") != 0 \
				&& (file->stat.st_mode & S_IFDIR) == S_IFDIR)
		{
			if (file->name[0] != '.' || opt_A != 0)
			{
				ft_display_path(file->path);
				ret = ft_ls_noargs(file->path, buff, opt_R, opt_A);
			}
			if (ret < 0)
				return (ret);
		}
		i++;
	}
	return (1);
}

/*
** Ouverture d'un dossier et lecture de celui-ci recursif ou non suivant
** le status de opt_R
*/

extern int			ft_ls_noargs(char *path, t_list **buff, int opt_R, int opt_A)
{
	DIR				*dd;
	t_dirent		*ndetail;
	t_file			file;
	int				ret;

	ret = 1;
	if (!(ft_buff_new(buff, LS_BUFFSIZE)))
		return (ERR_CODE_1);
	else if (!(dd = opendir(path)))
		ret = ft_err_opendir();
	while (ret > 0 && (ndetail = readdir(dd)) != 0)
	{
		file.err = 0;
		file.path = ft_strattach(path, ndetail->d_name, "/");
		ft_strcpy(file.name, ndetail->d_name);
		if (lstat(file.path, &file.stat))
			file.err = errno;
		ft_buff_insert(buff, &file, LS_BUFFSIZE);
	}
	ft_sort_file((t_file *)ft_buff_get(*buff)->buff, ft_buff_get(*buff)->cr);
	ft_display_ls((t_buff *)(*buff)->content);
	if (opt_R > 0)
		ft_ls_subdir(buff, opt_R, opt_A);
	return (ret);
}
