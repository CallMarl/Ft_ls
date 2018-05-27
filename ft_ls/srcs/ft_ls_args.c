/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:02:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/27 15:11:49 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

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
