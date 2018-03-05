/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_delarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:01:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 14:50:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void		ft_param_delarr(t_param **param)
{
	size_t		i;

	if (param != 0)
	{
		i = 0;
		while (i < FT_PARAM_NBMAX)
		{
			(*param)[i].key = 0;
			(*param)[i].val = 0;
			i++;
		}
		ft_memdel((void **)param);
	}
}
