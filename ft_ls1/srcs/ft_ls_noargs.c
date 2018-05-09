/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_noarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:04:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/09 19:07:54 by pprikazs         ###   ########.fr       */
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
	t_file			file;

	if (lstat(path, &file.stat))
		return (errno); // Erreur lecture fichier
	if (!(dd = opendir(path))) // Ajout de la fonction de retourn d'erreur avrc errno
		return (-1); // ft_err_diropen(errno);
	(void)path;
	(void)opt_R;
	return (1);
}
