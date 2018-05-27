/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_args_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 15:04:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/27 15:12:53 by pprikazs         ###   ########.fr       */
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

extern int
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
	ft_ls_argsfile_display(t_file *arr_file, int count)
{
	t_buff			tmp;

	ft_sort_file(arr_file, count);
	tmp.buff = (void *)arr_file;
	tmp.cr = count;
	if (count != 0)
	{
		ft_display_ls(&tmp, 0);
		ft_putchar('\n');
	}
}

extern void
	ft_ls_argsfile(t_buff *buff, t_file *arr_file, int count, t_file *arr_dir)
{
	size_t			i;
	size_t			j;
	t_file			*file;

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
	ft_ls_argsfile_display(arr_file, count);
}

/*
** Fait un appel à ft_ls_noarg pour chacun des dossier du tableau arr_dir
*/

extern int
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
