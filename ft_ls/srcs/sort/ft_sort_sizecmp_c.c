/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sizecmp_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:35:09 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:13:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "ft_ls.h"

extern int
	ft_sort_sizecmp_c(const void *f1, const void *f2)
{
	off_t			tmp;

	tmp = ((t_file *)f2)->stat.st_size - ((t_file *)f1)->stat.st_size;
	if (tmp == 0)
		tmp = ft_sort_filecmp_c(f1, f2);
	return ((int)tmp);
}
