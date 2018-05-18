/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupskel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:50:22 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:57 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern int			ft_setupskel(t_skel **skel, int type, char *val, int nb)
{
	int				i;

	i = 1;
	while (i < skel[type][0].val)
	{
		if (!ft_strcmp(val, skel[type][i].spe))
		{
			if (skel[type][i].val < nb)
				skel[type][i].val = nb;
			return (1);
		}
		i++;
	}
	return (0);
}
