/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_timecmp_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:41:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 11:39:01 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#ifndef _POSIX_SOURCE

extern int			ft_sort_timecmp_c(const void *f1, const void *f2)
{
	time_t			tmp;

	tmp = ((t_file *)f2)->stat.st_ctimespec.tv_sec - \
		  ((t_file *)f1)->stat.st_ctimespec.tv_sec;
	if (tmp == 0)
		tmp = ft_sort_filecmp_c(f1, f2);
	return (tmp);
}

#else

extern int			ft_sort_timecmp_c(const void *f1, const void *f2)
{
	time_t			tmp;

	tmp = ((t_file *)f2)->stat.st_ctim.tv_sec - \
		  ((t_file *)f1)->stat.st_ctim.tv_sec;
	if (tmp == 0)
		tmp = ft_sort_filecmp_c(f1, f2);
	return (tmp);
}

#endif
