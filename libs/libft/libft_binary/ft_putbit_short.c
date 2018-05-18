/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:07 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:23:59 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putbit_short(short val)
{
	short	pow;
	short	tmp;

	tmp = val;
	if (val < 0)
	{
		pow = 8 * sizeof(short) - 1;
		val = -val;
		tmp = 0;
		tmp = (unsigned short)(val + (ft_pow(2, pow)));
		val = (unsigned short)tmp;
	}
	ft_putbit_ushort(val);
}
