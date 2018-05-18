/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_insertnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:18:32 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:23:15 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insert un nombre dans un chaine de caractere
*/

extern char
	*ft_utils_insertnbr(char *str, int nbr)
{
	int size;
	int tmp;

	if (nbr == -2147483648)
	{
		str += ft_strcpy_x(str, "-2");
		nbr = nbr % 2000000000;
		nbr = -nbr;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	size = 1;
	tmp = nbr;
	while ((tmp = tmp / 10) != 0)
		size = size * 10;
	while (size)
	{
		*str++ = (char)((nbr / size) + 48);
		nbr %= size;
		size /= 10;
	}
	return (str);
}
