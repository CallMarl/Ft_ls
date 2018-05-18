/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:15:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/24 16:15:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** Vérifie les carcatères spéciaux en début de chaine pour atoi.
*/

static const char		*checkspecial(const char *str)
{
	while (1)
	{
		if (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\v' || \
				*str == '\r' || *str == '\n')
		{
			str++;
		}
		else
			break ;
	}
	return (str);
}

/*
** Tranforme la chaine de caractere numéric (si contenant des caracteres
** numérique) en un int et le retourn.
*/

extern uintmax_t		ft_atoum(const char *str)
{
	int					neg;
	uintmax_t			nbr;

	neg = 0;
	nbr = 0;
	str = checkspecial(str);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg = 1;
	}
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			nbr = nbr * 10 - ((int)*str - '0');
		else
			return ((neg == 1) ? nbr : -nbr);
		str++;
	}
	return ((neg == 1) ? nbr : -nbr);
}
