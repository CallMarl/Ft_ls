/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:02:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/15 11:20:18 by pprikazs         ###   ########.fr       */
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

static int			ft_ls_argserr(t_list **buff, int count)
{
	char			**arr_err;
	size_t			i;
	t_buff			*tmp;

	if (!(arr_err = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		return (ERR_CODE_1);
	arr_err[count] = 0;
	i = 0;
	count = 0;
	tmp = (t_buff *)(*buff)->content;
	while (i < tmp->cr)
	{
		if (ft_buff_getfile(tmp, i)->err != 0)
			arr_err[count++] = ft_buff_getfile(tmp, i)->name;
		i++;
	}
	ft_qsort((void *)arr_err, count, sizeof(char *), &ft_sort_strcmp_c);
	//Appel la fonction de display d'erreur
	return (1);
}

/*
** Récupère dans le buffer tout les appel à lstat correspondant à un fichier
** les range par ordre ascii et les affiche. Elle recupère aussi tout les appel
** a lstat correcpondant et les place dans le tableau arr_dir par soucie de 
** performance.
*/


static int			ft_ls_argsfile(t_list **buff, t_file *arr_file, \
		int count, t_file *arr_dir)
{
	size_t			i;
	size_t			j;
	t_buff			*tmp;

	i = 0;
	j = 0;
	count = 0;
	tmp = (t_buff *)(*buff)->content;
	while (i < tmp->cr)
	{
		if (ft_buff_getfile(tmp, i)->err == 0 && \
				(ft_buff_getfile(tmp, i)->stat.st_mode & S_IFDIR) == 0)
			ft_strcpy(arr_file[count++].name, ft_buff_getfile(tmp, i)->name);
		else if (ft_buff_getfile(tmp, i)->err == 0 && \
				(ft_buff_getfile(tmp, i)->stat.st_mode & S_IFDIR) != 0)
			ft_strcpy(arr_dir[j++].name, ft_buff_getfile(tmp, i)->name);
		i++;
	}
	int z = 0;
	while (z < count)
	{
		ft_putendl(arr_file[z++].name);
	}
	ft_sort_file(arr_file, count);
	// Appel display arr file
	return (1);
}

/*
** Fait un appel à ft_ls_noarg pour chacun des dossier du tableau arr_dir
*/

static int			ft_ls_argsdir(t_list **buff, t_file *arr_dir, \
		int count, _Bool opt_R)
{
	int 			i;

	i = 0;
	ft_sort_file(arr_dir, count);
	while (i < count)
	{
		ft_display_path(arr_dir[i].name);
		ft_ls_noargs(ft_strdup(arr_dir[i].name), buff, opt_R, ft_param_get('a'));
		i++;
	}
	return (1);
}

/*
** Fonction de lancement de ls avec des argument elle display soit les fichier
** soit elle appel ft_ls_noargs() dans le cas d'un dossier
*/

static int			ft_ls_argslaunch(t_list **buff, int count[3], int opt_R)
{
	t_file			*arr_dir;
	t_file			*arr_file;
	int				i;
	int				ret;

	if (!(arr_file = (t_file *)ft_memalloc(sizeof(t_file) * (count[1] + 1))))
		return (ERR_CODE_1);
	else if (!(arr_dir = (t_file *)ft_memalloc(sizeof(t_file) * (count[2] + 1))))
		return (ERR_CODE_1);
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			ret = ft_ls_argserr(buff, count[i]);
		else if (i == 1)
			ret = ft_ls_argsfile(buff, arr_file, count[i], arr_dir);
		else
			ret = ft_ls_argsdir(buff, arr_dir, count[i], opt_R);
		i++;
	}
	return (ret);
}

/*
** Initialisation d'un buffer dans le cas ou des chemin son spécifier en 
** argument de la commande ft_ls.
*/

extern int			ft_ls_args(char **argv, int size, t_list **buff)
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
