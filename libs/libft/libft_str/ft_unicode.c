/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:07:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 15:55:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

/*
** Parser un wchar_t en une chaine de caractere char * avec la bonne
** correspondance unicode
*/

static char			*ft_conv_aux(wchar_t val, size_t size, char mask, char *c)
{
	size_t			tmp;
	unsigned int	cpy;

	tmp = 0;
	cpy = (unsigned int)val;
	c[tmp++] = ((cpy >> (6 * (size - 1))) | mask);
	cpy <<= (32 - (6 * (size - 1)));
	cpy >>= (32 - (6 * (size - 1)));
	while (--size)
	{
		c[tmp++] = ((cpy >> (6 * (size - 1))) | 0x80);
		cpy <<= (32 - (6 * (size - 1)));
		cpy >>= (32 - (6 * (size - 1)));
	}
	return (c);
}

static int			ft_conv(wchar_t car, size_t size, char *c)
{
	char			mask;
	int				tmp;

	mask = 0x80;
	tmp = size - 1;
	while (tmp)
	{
		mask = ((mask >> 1) | 0x80);
		tmp--;
	}
	if (size > (size_t)MB_CUR_MAX)
		return (-1);
	ft_conv_aux(car, size, mask, c);
	return (0);
}

extern char			*ft_unicode(wchar_t val)
{
	char	*c;
	size_t	cpt;

	if (!(cpt = ft_charsize_u(val)))
		return (0);
	if (!(c = ft_strnew(cpt)))
		return (0);
	if ((val > 0x7F && MB_CUR_MAX >= 2) || val > 0xFF)
	{
		if ((ft_conv(val, cpt, c)) == -1)
			return (0);
	}
	else
		*c = (char)val;
	return (c);
}
