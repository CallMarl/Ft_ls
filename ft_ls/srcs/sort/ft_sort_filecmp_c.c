/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_filecmp_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:20:14 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 11:39:03 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern int			ft_sort_filecmp_c(const void *f1, const void *f2)
{
	return (ft_strcmp(((t_file *)f1)->name, ((t_file *)f2)->name));
}
