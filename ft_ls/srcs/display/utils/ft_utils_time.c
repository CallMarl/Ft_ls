/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:21:59 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:24:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

#ifndef _POSIX_SOURCE

extern char
	*ft_utils_time(struct stat *stat, char *str)
{
	time_t			file;
	time_t			current;
	char			*tmp1;
	char			*tmp2;

	current = time(0);
	file = stat->st_mtimespec.tv_sec;
	str = 0;
	str = ctime(&file);
	if (current - file > -15768000 && current - file < 15768000)
		str = ft_strsub(str, 4, 12);
	else
	{
		tmp1 = ft_strsub(str, 4, 7);
		tmp2 = ft_strsub(str, 20, 4);
		str = ft_strjoin(tmp1, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	return (str);
}

#else

extern char
	*ft_utils_time(struct stat *stat, char *str)
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
		tmp2 = ft_strsub(str, 20, 4);
		str = ft_strjoin(tmp1, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	return (str);
}

#endif
