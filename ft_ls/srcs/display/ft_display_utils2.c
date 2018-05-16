/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:32:19 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/16 22:49:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include "libft.h"
#include "ft_ls.h"

#ifndef _POSIX_SOURCE

	extern char			*ft_ls_time(struct stat *stat, char *str)
	{
		time_t			file;
		time_t			current;
		char			*tmp1;
		char			*tmp2;
		
		current = time(0);
		file = stat->st_mtimespec.tv_sec;
		str = 0;
		str = ctime(&file);
		if (current - file < 15768000 && current - file > 15768000)
			str = ft_strsub(str, 4, 12);
		else
		{
			tmp1 = ft_strsub(str, 4, 7);
			tmp2  = ft_strsub(str, 20, 4);
			str = ft_strjoin(tmp1, tmp2);
			ft_strdel(&tmp1);
			ft_strdel(&tmp2);
		}
		return (str);
	}

#else

	extern char			*ft_ls_time(struct stat *stat, char *str)
	{
		time_t			file;
		time_t			current;
		char			*tmp1;
		char			*tmp2;
		
		current = time(0);
		file = stat->st_mtim.tv_sec;
		str = 0;
		str = ctime(&file);
		if (current - file < 15768000 && current - file > 15768000)
			str = ft_strsub(str, 4, 12);
		else
		{
			tmp1 = ft_strsub(str, 4, 7);
			tmp2  = ft_strsub(str, 20, 4);
			str = ft_strjoin(tmp1, tmp2);
			ft_strdel(&tmp1);
			ft_strdel(&tmp2);
		}
		return (str);
	}

#endif

extern void			ft_mode(mode_t st_mode, char mode[12])
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


