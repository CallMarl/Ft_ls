/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:13:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/10 16:55:10 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void			ft_sort_file(t_file *files, size_t size)
{
	if (ft_param_get('r'))
		ft_qsort((void *)files, size, sizeof(t_file), &ft_sort_filecmp_d); 
	else
		ft_qsort((void *)files, size, sizeof(t_file), &ft_sort_filecmp_c); 
}