/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:46:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:55:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void			ft_conv_aux(wchar_t car, int size, char mask, char *str)
{
	int				tmp;
	unsigned int	cpy;

	tmp = 0;
	cpy = (unsigned int)car;
	str[tmp++] = ((cpy >> (6 * (size - 1))) | mask);
	cpy <<= (32 - (6 * (size - 1)));
	cpy >>= (32 - (6 * (size - 1)));
	while (--size)
	{
		str[tmp++] = ((cpy >> (6 * (size - 1))) | 0x80);
		cpy <<= (32 - (6 * (size - 1)));
		cpy >>= (32 - (6 * (size - 1)));
	}
}

static int			ft_conv(wchar_t car, size_t size, char *str)
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
	ft_conv_aux(car, size, mask, str);
	return (0);
}

extern int			ft_unicode_str(wchar_t *str, char **uni)
{
	int				i;
	int				cpt;
	size_t			tmp;

	if ((cpt = ft_strsize_u(str)) < 0)
		return (-1);
	if (!(*uni = ft_strnew((size_t)cpt)))
		return (-1);
	i = 0;
	cpt = 0;
	while (str[i])
	{
		tmp = ft_charsize_u(str[i]);
		if ((str[i] > 0x7F && MB_CUR_MAX >= 2) || str[i] > 0xFF)
		{
			if ((ft_conv(str[i], tmp, &(*uni)[cpt])) == -1)
				return (-1);
		}
		else
			(*uni)[cpt] = (char)str[i];
		cpt += tmp;
		i++;
	}
	return ((int)ft_strlen(*uni));
}
