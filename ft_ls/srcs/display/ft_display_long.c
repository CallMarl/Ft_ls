/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:53:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/15 12:43:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <stddef.h>
#include <sys/types.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"

static void			ft_display_mm(char *str, t_file *file, char *time, char *mode)
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

static void			ft_display_classic(char *str, t_file *file, char *time, char *mode)
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

static void			ft_display_long_aux(t_file *file, char *str, int mm, int opt_l)
{
	char			mode[12];
	char 			*time;

	ft_mode(file->stat.st_mode, mode);
	time = 0;
	time = ft_ls_time(&file->stat.st_mtimespec.tv_sec, time);
	if (mm != 0)
		ft_display_mm(str, file, time, mode);
	else
		ft_display_classic(str, file, time, mode);
	ft_display_file(file, opt_l);
	ft_putchar('\n');
}

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

/*
** Affichage basic des dossier comme avec ls -1
*/

extern void			ft_display_long(t_buff *buff, int opt_a, int opt_l)
{
	size_t			i;
	t_file			*file;
	t_disp			disp;
	char			*str;

	str = 0;
	ft_disp_init(&disp);
	ft_display_prepare(buff, &disp, opt_a);
	ft_display_preparestr(&disp, &str);
	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.' || opt_a != 0)
			ft_display_long_aux(file, str, disp.major + disp.minor, opt_l);
		i++;
	}
}
