/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:00 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:23:48 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d' un long en binaire
*/

void		ft_putbit_long(long val)
{
	long			pow;
	unsigned long	tmp;

	if (val < 0)
	{
		pow = 8 * sizeof(unsigned long) - 1;
		val = -val;
		tmp = 1;
		tmp = val | (tmp << pow);
		val = (unsigned long)tmp;
	}
	ft_putbit_ulong(val);
}
