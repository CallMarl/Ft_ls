/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:02:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/09 17:18:31 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <errno.h>
	#include <string.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Récupère dans le buffeur tout les appel à lstat ayant générer une erreur
** les range par ordre ascii. Et affiche les erreurs
*/

static int			ft_ls_argserr(t_list *buff, int count)
{
	char			**arr_err;
	size_t			i;
	t_buff			*tmp;

	if (!(arr_err = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		return (ERR_CODE_1);
	arr_err[count] = 0;
	i = 0;
	count = 0;
	tmp = (t_buff *)buff->content;
	while (i < tmp->cr)
	{
		if (ft_buff_get(tmp, i)->err != 0)
			arr_err[count++] = ft_buff_get(tmp, i)->name;
		i++;
	}
	ft_qsort((void *)arr_err, count, sizeof(char *), &ft_sort_strcmp_c);
ft_putendl("\nfile err : ");
ft_debug_strarr(arr_err);
	//Appel la fonction de display d'erreur
	return (1);
}

/*
** Récupère dans le buffer tout les appel à lstat correspondant à un fichier
** les range par ordre ascii et les affiche.
*/

static int			ft_ls_argsfile(t_list *buff, char **arr_file, int count, char **arr_dir)
{
	size_t			i;
	size_t			j;
	t_buff			*tmp;

	i = 0;
	j = 0;
	count = 0;
	tmp = (t_buff *)buff->content;
	while (i < tmp->cr)
	{
		if (ft_buff_get(tmp, i)->err == 0 && \
				(ft_buff_get(tmp, i)->stat.st_mode & S_IFDIR) == 0)
			arr_file[count++] = ft_buff_get(tmp, i)->name;
		else if (ft_buff_get(tmp, i)->err == 0 && \
				(ft_buff_get(tmp, i)->stat.st_mode & S_IFDIR) != 0)
			arr_dir[j++] = ft_buff_get(tmp, i)->name;
		i++;
	}
	ft_qsort((void *)arr_file, count, sizeof(char *), &ft_sort_strcmp_c);
ft_putendl("\nfile : ");
ft_debug_strarr(arr_file);
	// Appel display arr file
	return (1);
}

/*
** Récupère dans le buffer tout les appel à lstat correspondant à un dossier
** et fait un appel à ft_ls_noarg pour chacun d'entre eux.
*/

static int			ft_ls_argsdir(t_list *buff, char **arr_dir, int count, _Bool opt_R)
{
	//Appel la fonction ft_ls_noarg()
	ft_qsort((void *)arr_dir, count, sizeof(char *), &ft_sort_strcmp_c);
ft_putendl("\ndirs : ");
ft_debug_strarr(arr_dir);
	(void)buff;
	(void)count;
	(void)opt_R;
	return (1);
}

/*
** Fonction de lancement de ls avec des argument elle display soit les fichier
** soit elle appel ft_ls_noargs() dans le cas d'un dossier
*/

static int			ft_ls_argslaunch(t_list *buff, int count[3], _Bool opt_R)
{
	char			**arr_dir;
	char			**arr_file;
	int				i;
	int				ret;

	if (!(arr_file = (char **)ft_memalloc(sizeof(char *) * (count[1] + 1))))
		return (ERR_CODE_1);
	else if (!(arr_dir = (char **)ft_memalloc(sizeof(char *) * (count[2] + 1))))
		return (ERR_CODE_1);
	arr_file[count[1]] = 0;
	arr_dir[count[2]] = 0;
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

	i = 0;
	while (i < 3)
		count[i++] = 0;
	i = 0;
	while (i < size)
	{
		file.name = argv[i];
		file.err = 0;
		if (lstat(argv[i], &file.stat) == -1)
			file.err = errno;;
		if (ft_buff_insert(buff, &file, size) == -1)
			return (ERR_CODE_1);
		if (file.err != 0)
			(count[0])++;
		else
			((file.stat.st_mode & S_IFDIR) != 0) ? (count[2])++ : (count[1])++;
		i++;
	}
	return (ft_ls_argslaunch(*buff, count, ft_param_get('R')));
}

