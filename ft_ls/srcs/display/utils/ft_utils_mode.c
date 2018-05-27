/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:23:22 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/27 14:42:33 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

extern void
	ft_utils_mode(mode_t st_mode, char mode[12])
{
	char			*mode_type;
	int				count;
	static char		*right[] = {"---", "--x", "-w-", "-wx", "r--", "r-x",  \
		"rw-", "rwx"
	};

	mode_type = "pcdb-ls ";
	mode[0] = mode_type[ft_utils_modetype(st_mode)];
	count = 1;
	count += ft_strcpy_x(&mode[count], right[(st_mode >> 6) & 7]);
	count += ft_strcpy_x(&mode[count], right[(st_mode >> 3) & 7]);
	count += ft_strcpy_x(&mode[count], right[(st_mode) & 7]);
	if ((S_ISVTX & st_mode) != 0)
		mode[9] = (S_IXOTH & st_mode) ? 't' : 'T';
	if ((S_ISGID & st_mode) != 0)
		mode[6] = (S_IXGRP & st_mode) ? 's' : 'S';
	if ((S_ISUID & st_mode) != 0)
		mode[3] = (S_IXUSR & st_mode) ? 's' : 'S';
	mode[10] = ' ';
	mode[11] = '\0';
}
