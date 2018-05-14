/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:46:06 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 15:33:30 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Fonction auxiliaire a ft_display_prpepare.
*/

static void				ft_display_prepare_aux(t_disp *disp, t_file *file)
{
	int					tmp;

	tmp = ft_nbweight(file->stat.st_nlink);
	disp->nlink = (tmp > disp->nlink) ? tmp : disp->nlink;
	tmp = ft_getuidlen(file->stat.st_uid);
	disp->uid = (tmp > disp->uid) ? tmp : disp->uid;
	tmp = ft_getgidlen(file->stat.st_gid);
	disp->gid = (tmp > disp->gid) ? tmp : disp->gid;
	if (file->stat.st_rdev != 0)
	{
		tmp = ft_nbweight(major(file->stat.st_rdev));
		disp->major = (tmp > disp->major) ? tmp : disp->major;
		tmp = ft_nbweight(minor(file->stat.st_rdev));
		disp->minor = (tmp > disp->minor) ? tmp : disp->minor;
	}
	else
	{
		tmp = ft_nbweight(file->stat.st_size);
		disp->size = (tmp > disp->size) ? tmp : disp->size;
	}
}

/*
** Dans le cas de l'option -l prepare compte la longueur de chacun des
** éléments, sauvegarde dans disp la plus grande valeur trouvé.
*/

extern void				ft_display_prepare(t_buff *buff, t_disp *disp, int pa)
{
	size_t				i;
	t_file				*file;

	i = 0;
	while (i < buff->cr)
	{
		file = ft_buff_getfile(buff, i);
		if (file->name[0] != '.')
			ft_display_prepare_aux(disp, file);
		else if (pa != 0)
			ft_display_prepare_aux(disp, file);
		i++;
	}
}
