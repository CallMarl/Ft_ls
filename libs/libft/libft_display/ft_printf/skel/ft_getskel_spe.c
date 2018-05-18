/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getskel_spe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:53:34 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern char			*ft_getskel_spe(t_skel **skel, int type)
{
	int				size;
	int				i;

	if (type >= FT_SKEL_SIZE)
		return (0);
	i = 1;
	size = skel[type][0].val;
	while (i < size)
	{
		if (skel[type][i].val)
			return (skel[type][i].spe);
		i++;
	}
	return (0);
}
