/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:41:52 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:23:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d'un int en binaire
*/

void		ft_putbit_int(int val)
{
	int				pow;
	unsigned int	tmp;

	if (val < 0)
	{
		pow = 8 * sizeof(int) - 1;
		val = -val;
		tmp = 0;
		tmp = (unsigned int)(val + (ft_pow(2, pow)));
		val = (unsigned int)tmp;
	}
	ft_putbit_uint(val);
}
