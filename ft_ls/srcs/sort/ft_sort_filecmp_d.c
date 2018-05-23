/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_filecmp_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:21:41 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:13:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern int
	ft_sort_filecmp_d(const void *f1, const void *f2)
{
	return (ft_strcmp(((t_file *)f2)->name, ((t_file *)f1)->name));
}
