/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_noarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:04:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 01:23:22 by                  ###   ########.fr       */
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
** Fonction récursive à ft_ls_noargs(), cette fonction iter sur l'ensemble
** des sous dossiers d'un dossier courant. Appelé uniquement si opt_R est
** différent de zero.
*/

static int			ft_ls_subdir(t_list **buff, int opt_R, int opt_a)
{
	int				ret;
	size_t			i;
	t_buff			*tmp;
	t_file			*file;

	i = 0;
	tmp = (t_buff *)(*buff)->content;
	while (i < tmp->cr)
	{
		file = ft_buff_getfile(tmp, i);
		if (ft_strcmp(file->name, ".") != 0 && ft_strcmp(file->name, "..") != 0 \
				&& (file->stat.st_mode & S_IFDIR) == S_IFDIR)
		{
			if (file->name[0] != '.' || opt_a != 0)
			{
				ft_display_path(file->path);
				ret = ft_ls_noargs(file->path, buff, opt_R, opt_a);
			}
			if (ret < 0)
				return (ret);
		}
		i++;
	}
	return (1);
}

/*
** Fonction d'ouverture et de lecture d'un dossier, affiche une erreur dans le
** cas ou l'ouverture echoue. Si opt_R est différent de zero alors elle iterera
** dans les sous dossier.
*/

static int			ft_ls_noargs_aux(char *path, t_list **buff, int opt_R, int opt_a)
{
	int				ret;
	DIR				*dd;
	t_dirent		*ndetail;
	t_file			file;

	ret = 1;
	dd = 0;
	if ((dd = opendir(path)) == 0)
		return (ft_err_basic());
	while (ret > 0 && (ndetail = readdir(dd)) != 0)
	{
		if (path[0] == '/' && path[1] == '\0')
			file.path = ft_strjoin("/", ndetail->d_name);
		else
			file.path = ft_strattach(path, ndetail->d_name, "/");
		file.err = (lstat(file.path, &file.stat)) ? errno : 0;
		ft_strcpy(file.name, ndetail->d_name);
		ft_buff_insert(buff, &file, LS_BUFFSIZE);
	}
	ft_sort_file((t_file *)ft_buff_get(*buff)->buff, ft_buff_get(*buff)->cr);
	ret = ft_display_ls((t_buff *)(*buff)->content);
	if (ret >= 0 && opt_R > 0)
		ret = ft_ls_subdir(buff, opt_R, opt_a);
	ft_lstremove(buff, 0, &ft_buff_delelem);
	closedir(dd);
	return (ret);
}

/*
** Lecture de la path, dans le cas ou un seul argument est spécifié et que 
** cette argument est différent d'un dossier, la fonction affiche cette
** éléments sinon elle tente de lire dans le dossier.
*/

extern int			ft_ls_noargs(char *path, t_list **buff, int opt_R, int opt_a)
{
	int				ret;
	t_file			file;

	ret = 1;
	if (!(ft_buff_new(buff, LS_BUFFSIZE)))
		return (ERR_CODE_1);
	else if (lstat(path, &(file.stat)))
		ret = ft_err_basic();
	else if (S_ISDIR(file.stat.st_mode) || S_ISLNK(file.stat.st_mode))
		ret = ft_ls_noargs_aux(path, buff, opt_R, opt_a);
	else
	{
		ft_strcpy(file.name, path);
		ft_display_file(&file, ft_param_get('l'));
		ft_putchar('\n');
	}
	return (ret);
}
