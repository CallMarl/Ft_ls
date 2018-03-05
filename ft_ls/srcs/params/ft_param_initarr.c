/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_initarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:24:02 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 12:22:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_ls.h"

extern t_params		*ft_params_init(size_t max_size)
{
	t_params		*arr;
	size_t			i;

	if (!(arr = (t_param *)ft_memalloc(sizeof(t_param) * (max_size + 1))))
		return (0);
	while (i < max_size + 1)
	{
		arr[i]->key = 0;
		arr[i]->val = 0;
	}
	return (*arr);
}
