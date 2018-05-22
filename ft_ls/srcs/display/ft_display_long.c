/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:53:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/22 16:52:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <stddef.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

static void
	ft_display_mm(char *str, t_file *file, char *time, char *mode)
{
	struct passwd		*pwd;
	struct group		*grp;
	char				*uid_str;
	char				*gid_str;

	pwd = getpwuid(file->stat.st_uid);
	uid_str = (pwd) ? pwd->pw_name : ft_itoa(file->stat.st_uid);
	grp = getgrgid(file->stat.st_gid);
	gid_str = (grp) ? grp->gr_name : ft_itoa(file->stat.st_gid);
	ft_printf(str, \
			mode, \
			file->stat.st_nlink, \
			uid_str, \
			gid_str, \
			(file->stat.st_rdev) ? major(file->stat.st_rdev) : 0, \
			(file->stat.st_rdev) ? minor(file->stat.st_rdev) : 0, \
			time);
	if (pwd == 0)
		ft_strdel(&uid_str);
	if (grp == 0)
		ft_strdel(&gid_str);
}

static void
	ft_display_classic(char *str, t_file *file, char *time, char *mode)
{
	struct passwd		*pwd;
	struct group		*grp;
	char				*uid_str;
	char				*gid_str;

	pwd = getpwuid(file->stat.st_uid);
	uid_str = (pwd) ? pwd->pw_name : ft_itoa(file->stat.st_uid);
	grp = getgrgid(file->stat.st_gid);
	gid_str = (grp) ? grp->gr_name : ft_itoa(file->stat.st_gid);
	ft_printf(str, \
			mode, \
			file->stat.st_nlink, \
			uid_str, \
			gid_str, \
			file->stat.st_size, \
			time);
	if (pwd == 0)
		ft_strdel(&uid_str);
	if (grp == 0)
		ft_strdel(&gid_str);
}

static void
	ft_display_long_aux(t_buff *buff, char *str, int mm, int opt_a)
{
	char			mode[12];
	char			*time;
	size_t			i;
	t_file			*file;

	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.' || opt_a != 0)
		{
			ft_utils_mode(file->stat.st_mode, mode);
			time = 0;
			time = ft_utils_time(&file->stat, time);
			if (mm != 0)
				ft_display_mm(str, file, time, mode);
			else
				ft_display_classic(str, file, time, mode);
			ft_display_file(file, 1);
			ft_putchar('\n');
			ft_strdel(&time);
		}
		i++;
	}
}

/*
** Structure qui indique la largeur des colone pour chacun des précision
*/

static void
	ft_disp_init(t_disp *disp)
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

extern int
	ft_display_long(t_buff *buff, int opt_a)
{
	t_disp			disp;
	char			*str;
	size_t			block;

	str = 0;
	ft_disp_init(&disp);
	ft_display_prepare(buff, &disp, opt_a, &block);
	if (!(str = ft_display_preparestr(&disp)))
		return (ERR_CODE_1);
	ft_putstr("total ");
	ft_printf("%ld", block);
	ft_putchar('\n');
	ft_display_long_aux(buff, str, disp.major + disp.minor, opt_a);
	ft_strdel(&str);
	return (1);
}
