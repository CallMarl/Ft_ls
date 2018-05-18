/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:39:51 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:23:11 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_base2 transforme la valeur char val en une string binaire representant ca
** valeur binaire.
*/

char	*ft_base2(unsigned char val, char *str)
{
	int	i;
	int	bits;

	i = 7;
	bits = 8;
	str[8] = '\0';
	while (bits > 0)
	{
		str[i] = (val % 2) + 48;
		val /= 2;
		i--;
		bits--;
	}
	return (str);
}
