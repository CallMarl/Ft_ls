/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setskel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:47:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:53 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern int			ft_setskel(t_skel **skel, int type, char *val, int nb)
{
	int				i;
	char			*define;

	i = 1;
	while (i < skel[type][0].val)
	{
		if (!ft_strcmp(val, skel[type][i].spe))
		{
			skel[type][i].val = nb;
			return (1);
		}
		i++;
	}
	define = "sSpdDioOuUxXcC%jzlh+ -0#%";
	if (type == FT_DISPLAY_SPE && ft_strchr(define, (*val)) == 0)
	{
		i--;
		skel[type][i].val = nb;
		return (1);
	}
	return (0);
}
