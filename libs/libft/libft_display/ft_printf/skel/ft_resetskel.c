/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetskel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:04:40 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:49 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern t_skel		**ft_reset_skel(t_skel **skel)
{
	int				i;
	int				j;

	i = 0;
	while (i < FT_SKEL_SIZE)
	{
		j = 1;
		while (j < skel[i][0].val)
		{
			skel[i][j].val = 0;
			j++;
		}
		i++;
	}
	ft_setskel(skel, FT_ACCURACY_SPE, "2", -1);
	return (skel);
}
