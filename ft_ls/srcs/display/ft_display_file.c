/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:31:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 19:10:06 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ls.h"

static void			ft_display_link(char *path)
{
	char			link[LS_BUFFSIZE];
	size_t			last;

	ft_putstr(" -> ");
	if (!(last = readlink(path, link, LS_BUFFSIZE)))
		ft_err_basic();
	else
	{
		link[last] = '\0';
		ft_putstr(link);
	}
}

extern void			ft_display_file(t_file *file, int opt_l)
{
	if (S_ISCHR(file->stat.st_mode))
		ft_putcolor_8("33", file->name);
	else if (S_ISCHR(file->stat.st_mode))
		ft_putcolor_24("000;255;255", file->name);
	else if (S_ISBLK(file->stat.st_mode))
		ft_putcolor_24("001;049;180", file->name);
	else if (S_ISREG(file->stat.st_mode))
	{
		if ((file->stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
			ft_putcolor_24("198;008;000", file->name);
		else
			ft_putstr(file->name);
	}
	else if (S_ISLNK(file->stat.st_mode))
	{
		ft_putcolor_24("205;000;205", file->name);
		if (opt_l != 0)
			ft_display_link(file->path);
	}
	else if (S_ISSOCK(file->stat.st_mode))
		ft_putcolor_24("059;234;031", file->name);
	else
		ft_putcolor_24("255;255;255", file->name);
}
