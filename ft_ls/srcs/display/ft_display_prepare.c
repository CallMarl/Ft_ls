/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:46:06 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/13 19:16:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

static int				ft_nbweight(int nb)
{
	int					i;

	i = 1;
	while ((nb /= 10) > 0)
		i++;
	return (i);
}

static int				ft_getuidlen(int uid)
{
	struct passwd		*pwd;
	int					len;

	pwd = getpwuid(uid);
	len = ft_strlen(pwd->pw_name);
	//free(pwd);
	return (len);
}

static int				ft_getgidlen(int gid)
{
	struct group		*grp;
	int					len;

	grp = getgrgid(gid);
	len = ft_strlen(grp->gr_name);
	//free(grp);
	return (len);
}

static void				ft_display_prepare_aux(t_disp *disp, t_file *file)
{
	int					tmp;

	if (file->stat.st_rdev != 0)
	{
		tmp = ft_nbweight(file->stat.st_size);
		disp->size = (tmp > disp->size) ? tmp : disp->size;
	}
	else
	{
		tmp = ft_nbweight(major(file->stat.st_rdev));
		disp->major = (tmp > disp->major) ? tmp : disp->major;
		tmp = ft_nbweight(minor(file->stat.st_rdev));
		disp->minor = (tmp > disp->minor) ? tmp : disp->minor;
	}
}

extern void				ft_display_prepare(t_buff *buff, t_disp *disp)
{
	size_t				i;
	int					tmp;

	i = 0;
	while (i < buff->cr)
	{
		tmp = ft_nbweight(ft_buff_getfile(buff, i)->stat.st_nlink);
		disp->nlink = (tmp > disp->nlink) ? tmp : disp->nlink;
		tmp = ft_getuidlen(ft_buff_getfile(buff, i)->stat.st_uid);
		disp->uid = (tmp > disp->uid) ? tmp : disp->uid;
		tmp = ft_getgidlen(ft_buff_getfile(buff, i)->stat.st_gid);
		disp->uid = (tmp > disp->gid) ? tmp : disp->gid;
		ft_display_prepare_aux(disp, ft_buff_getfile(buff, i));
		i++;
	}
}
