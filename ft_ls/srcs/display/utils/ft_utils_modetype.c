/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_modetype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:19:38 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 11:26:46 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>

/*
** Return a value for the type mode
*/

extern int			ft_utils_modetype(mode_t st_mode)
{
	if (S_ISFIFO(st_mode))
		return (0);
	else if (S_ISCHR(st_mode))
		return (1);
	else if (S_ISDIR(st_mode))
		return (2);
	else if (S_ISBLK(st_mode))
		return (3);
	else if (S_ISREG(st_mode))
		return (4);
	else if (S_ISLNK(st_mode))
		return (5);
	else if (S_ISSOCK(st_mode))
		return (6);
	else
		return (7);
}
