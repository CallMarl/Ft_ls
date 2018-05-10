/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_noarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:04:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/10 12:11:25 by pprikazs         ###   ########.fr       */
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
** Ouverture d'un dossier et lecture de celui-ci
*/

extern int			ft_ls_noargs(char *path, t_list **buff, _Bool opt_R)
{
	DIR				*dd;
	size_t			dir_size;
	t_file			file;
	t_dirent		*ninfo;

	if (lstat(path, &file.stat))
		return (errno); // Erreur lecture fichier
	dir_size = file.stat.st_link;
	else if (!(ft_buff_new(buff, dir_size)))
		return (ERR_CODE_1);
	else if (!(dd = opendir(path))) // Ajout de la fonction de retourn d'erreur avrc errno
		return (-1); // ft_err_diropen(errno);
	while (!(ndetail = readdir(dd)))
	{
		file.name = ft_strcpy(ndetail.d_name);
		file.path = ft_strattach(path, ndetail.d_name, '/');	
		if (lstat(path, &file.stat))
			return (errno); // Erreur lecture fichier
		ft_buff_insert(buff, file, dir_size);
	}
	return (1);
}
