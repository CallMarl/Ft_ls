/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:41:44 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 17:46:40 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d' un char en binaire
*/

void		ft_putbit_char(char val)
{
	char				pow;
	unsigned char		tmp;

	if (val < 0)
	{
		pow = 8 * sizeof(char) - 1;
		val = -val;
		tmp = 0;
		tmp = (unsigned char)(val + (ft_pow(2, pow)));
		val = (unsigned char)tmp;
	}
	ft_putbit_uchar(val);
}
