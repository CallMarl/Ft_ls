/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:02:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 11:43:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Récupère dans le buffeur tout les appel à lstat ayant générer une erreur
** les range par ordre ascii. Et affiche les erreurs
*/

static int
	ft_ls_argserr(t_buff *buff, int count)
{
	t_file			*arr_err;
	size_t			i;
	t_file			*file;
	int				ret;

	if (!(arr_err = (t_file *)ft_memalloc(sizeof(t_file) * (count))))
		return (ERR_CODE_1);
	i = 0;
	count = 0;
	while (i < buff->cr)
	{
		file = ft_buff_getfile(buff, i);
		if (file->err != 0)
		{
			ft_strcpy(arr_err[count].name, file->name);
			arr_err[count].err = file->err;
			count++;
		}
		i++;
	}
	ft_qsort((void *)arr_err, count, sizeof(t_file), &ft_sort_filecmp_c);
	ret = (count != 0) ? ft_err_args(arr_err, count) : 1;
	ft_memdel((void *)&arr_err);
	return (ret);
}

/*
** Récupère dans le buffer tout les appel à lstat correspondant à un fichier
** les range par ordre ascii et les affiche. Elle recupère aussi tout les appel
** a lstat correcpondant et les place dans le tableau arr_dir par soucie de
** performance.
*/

static void
	ft_ls_argsfile(t_buff *buff, t_file *arr_file, int count, t_file *arr_dir)
{
	size_t			i;
	size_t			j;
	t_file			*file;
	t_buff			tmp;

	i = 0;
	j = 0;
	count = 0;
	while (i < buff->cr)
	{
		file = ft_buff_getfile(buff, i);
		if (file->err == 0 && (S_ISDIR(file->stat.st_mode)
				|| (S_ISLNK(file->stat.st_mode) && (char *)file->name != 0
					&& file->name[ft_strlen(file->name) - 1] == '/')))
			ft_strcpy(arr_dir[j++].name, file->name);
		else if (file->err == 0)
		{
			arr_file[count].stat = file->stat;
			ft_strcpy(arr_file[count++].name, file->name);
			arr_file[count - 1].path = ft_strdup(arr_file[count - 1].name);
		}
		i++;
	}
	ft_sort_file(arr_file, count);
	tmp.buff = (void *)arr_file;
	tmp.cr = count;
	if (count != 0)
		ft_display_ls(&tmp);
}

/*
** Fait un appel à ft_ls_noarg pour chacun des dossier du tableau arr_dir
*/

static int
	ft_ls_argsdir(t_list **buff, t_file *arr_dir, int count, _Bool opt_r)
{
	int				i;
	int				ret;

	i = 0;
	ret = 1;
	ft_sort_file(arr_dir, count);
	while (i < count && ret >= 0)
	{
		if (i == 0)
			ft_display_path2(arr_dir[i].name);
		else
			ft_display_path1(arr_dir[i].name);
		ret = ft_ls_noargs(ft_strdup(arr_dir[i].name), \
				buff, opt_r, ft_param_get('a'));
		i++;
	}
	return (ret);
}

/*
** Fonction de lancement de ls avec des argument elle display soit les fichier
** soit elle appel ft_ls_noargs() dans le cas d'un dossier
*/

static int
	ft_ls_argslaunch(t_list **buff, int count[3], int opt_r)
{
	t_file			*arr_dir;
	t_file			*arr_file;
	int				i;
	int				ret;

	if (!(arr_file = (t_file *)ft_memalloc(sizeof(t_file) * (count[1] + 1))))
		return (ERR_CODE_1);
	if (!(arr_dir = (t_file *)ft_memalloc(sizeof(t_file) * (count[2] + 1))))
		return (ERR_CODE_1);
	i = 0;
	ret = 1;
	while (i < 3 && ret >= 0)
	{
		if (i == 0)
			ret = ft_ls_argserr(ft_buff_get(*buff), count[i]);
		else if (i == 1)
			ft_ls_argsfile(ft_buff_get(*buff), arr_file, count[i], arr_dir);
		else
			ret = ft_ls_argsdir(buff, arr_dir, count[i], opt_r);
		i++;
	}
	ft_memdel((void **)&arr_dir);
	ft_memdel((void **)&arr_file);
	return (ret);
}

/*
** Initialisation d'un buffer dans le cas ou des chemin son spécifier en
** argument de la commande ft_ls.
*/

extern int
	ft_ls_args(char **argv, int size, t_list **buff)
{
	int				i;
	int				count[3];
	t_file			file;

	if (!(ft_buff_new(buff, LS_BUFFSIZE)))
		return (ERR_CODE_1);
	i = 0;
	while (i < 3)
		count[i++] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcpy(file.name, argv[i]);
		file.err = 0;
		if (lstat(argv[i], &file.stat) == -1)
			file.err = errno;
		if (ft_buff_insert(buff, &file, LS_BUFFSIZE) == -1)
			return (ERR_CODE_1);
		else if (file.err != 0)
			(count[0])++;
		else
			((file.stat.st_mode & S_IFDIR) != 0) ? (count[2])++ : (count[1])++;
		i++;
	}
	return (ft_ls_argslaunch(buff, count, ft_param_get('R')));
}
