/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getskel_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:56:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:45 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern int			ft_getskel_val(t_skel **skel, int type, char *spe)
{
	int				size;
	int				i;

	if (type >= FT_SKEL_SIZE)
		return (0);
	i = 1;
	size = skel[type][0].val;
	while (i < size)
	{
		if (ft_strcmp(skel[type][i].spe, spe) == 0)
			return (skel[type][i].val);
		i++;
	}
	return (0);
}
