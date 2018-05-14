/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:53:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 15:40:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <stddef.h>
#include <sys/types.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Structure qui indique la largeur des colone pour chacun des précision
*/

static	void		ft_disp_init(t_disp *disp)
{
	disp->mode = 11;
	disp->nlink = 0;
	disp->uid = 0;
	disp->gid = 0;
	disp->size = 0;
	disp->major = 0;
	disp->minor = 0;
}

static void			ft_display_mode(mode_t st_mode, char mode[12])
{
	char			*mode_type;
	int				count;
	static char		*right[] = {"---", "--x", "-w-", "-wx", "r--", "r-x",  \
		"rw-", "rwx"
	};

	mode_type = "pcdb-ls ";
	mode[0] = mode_type[ft_modetype(st_mode)];
	count = 1;
	count += ft_strcpy_x(&mode[count], right[(st_mode >> 6) & 7]);
	count += ft_strcpy_x(&mode[count], right[(st_mode >> 3) & 7]);
	count += ft_strcpy_x(&mode[count], right[(st_mode) & 7]);
	if ((S_ISVTX & st_mode) != 0)
		mode[3] = (S_IXOTH & st_mode) ? 't' : 'T';
	else if ((S_ISGID & st_mode) != 0)
		mode[6] = (S_IXGRP & st_mode) ? 's' : 'l';
	else if ((S_ISUID & st_mode) != 0)
		mode[9] = (S_IXUSR & st_mode) ? 's' : 'S';
	mode[10] = ' '; // Acl read
	mode[11] = '\0';
}

static char			*ft_display_time(time_t *time, char *str)
{
	str = ctime(time);
	str = ft_strsub(str, 4, 12);
	return (str);
}

static void			ft_display_long_aux(t_file *file, char *str, int mm)
{
	char			mode[12];
	char 			*time;

	ft_display_mode(file->stat.st_mode, mode);
	time = 0;
	time = ft_display_time(&file->stat.st_mtimespec.tv_sec, time);
	if (mm != 0)
	{
		ft_printf(str, \
				mode, \
				file->stat.st_nlink, \
				getpwuid(file->stat.st_uid)->pw_name, \
				getgrgid(file->stat.st_gid)->gr_name, \
				(file->stat.st_rdev) ? major(file->stat.st_rdev) : 0, \
				(file->stat.st_rdev) ? minor(file->stat.st_rdev) : 0, \
				time
			);
	}
	else
	{
		ft_printf(str, \
				mode, \
				file->stat.st_nlink, \
				getpwuid(file->stat.st_uid)->pw_name, \
				getgrgid(file->stat.st_gid)->gr_name, \
				file->stat.st_size, \
				time
			);
	}
	ft_display_file(file);
}

/*
** Affichage basic des dossier comme avec ls -1
*/

extern void			ft_display_long(t_buff *buff, int pa)
{
	size_t			i;
	t_file			*file;
	t_disp			disp;
	char			*str;

	str = 0;
	ft_disp_init(&disp);
	ft_display_prepare(buff, &disp, pa);
	ft_display_preparestr(&disp, &str);
	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.')
			ft_display_long_aux(file, str, disp.major + disp.minor);
		else if (pa != 0)
			ft_display_long_aux(file, str, disp.major + disp.minor);
		i++;
	}
}
