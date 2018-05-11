/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_noarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:04:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/11 15:55:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Dans le cas de récursif rappel de noarg pour chaque dossier
*/

static int			ft_ls_subdir(t_list **buff, _Bool opt_R)
{
	size_t			i;
	t_buff			*tmp;
	t_file			*file;

	i = 0;
	tmp = (t_buff *)(*buff)->content;
	while (i < tmp->b_size)
	{
		file = ft_buff_get(tmp, i);
		if (ft_strcmp(file->name, ".") != 0 && ft_strcmp(file->name, "..") != 0 \
				&& (file->stat.st_mode & S_IFDIR) == S_IFDIR)
		{
			//display du chemin du dossier
			ft_putendl(ft_buff_get(tmp, i)->path);
			ft_ls_noargs(ft_buff_get(tmp, i)->path, buff, opt_R);
		}
		i++;
	}
	return (1);
}

/*
** Ouverture d'un dossier et lecture de celui-ci recursif ou non suivant
** le status de opt_R
*/

extern int			ft_ls_noargs(char *path, t_list **buff, _Bool opt_R)
{
	DIR				*dd;
	t_dirent		*ndetail;
	t_file			file;

	if (!(ft_buff_new(buff, LS_BUFFSIZE)))
		return (ERR_CODE_1);
	else if (!(dd = opendir(path)))
		return (-1); // ft_err_diropen(errno);
	while ((ndetail = readdir(dd)) != 0)
	{
		ft_strcpy(file.name, ndetail->d_name);
		file.path = ft_strattach(path, ndetail->d_name, "/");
		if (lstat(file.path, &file.stat))
			return (errno); // Erreur lecture fichier
		ft_buff_insert(buff, &file, LS_BUFFSIZE);
	}
	ft_sort_file((t_file *)((t_buff *)(*buff)->content)->buff, \
			((t_buff *)(*buff)->content)->cr); // Simplifier ces appel avec des accesseurs
ft_debug_buff((t_buff *)(*buff)->content);
	if (opt_R == 1)
		ft_ls_subdir(buff, opt_R);
	return (1);
}
