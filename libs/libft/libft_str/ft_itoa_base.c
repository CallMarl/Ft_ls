/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoal_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:48:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:33:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[j + 1] != '\0')
		{
			if (base[i] == base[j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		ft_nbconverted_size(intmax_t nbr, short base_len)
{
	int i;

	i = 0;
	while ((nbr / base_len) != 0)
	{
		i++;
		nbr /= base_len;
	}
	i++;
	return (i);
}

static char		*ft_base_convert(intmax_t nbr, char *base, char *convert,\
		int base_len)
{
	int			i;
	int			convert_len;
	uintmax_t	tmp;

	convert_len = ft_nbconverted_size(nbr, base_len);
	i = convert_len;
	if (nbr < 0)
	{
		tmp = (uintmax_t)-nbr;
		convert[0] = '-';
	}
	else
		tmp = nbr;
	while (i)
	{
		i--;
		convert[i] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (convert[0] == '\0')
		ft_memmove(convert, (convert + 1), convert_len + 1);
	return (convert);
}

extern char		*ft_itoa_base(intmax_t nbr, char *base)
{
	int		base_len;
	char	*convert;

	base_len = ft_strlen(base);
	if (!(ft_check_base(base)) || base_len == 0)
		return (0);
	if (!(convert = ft_strnew(ft_nbconverted_size(nbr, base_len) + 2)))
		return (0);
	return (ft_base_convert(nbr, base, convert, base_len));
}
