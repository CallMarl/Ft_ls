/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charsize_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:08:14 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:58:42 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

/*
** Donne la taille en octet d'un caractere unicode.
*/

size_t			ft_charsize_u(wchar_t c)
{
	int				cpt;

	cpt = 0;
	if (c > 0xFFFFF || c < 0 || (0xD800 <= c && c <= 0xDFFF))
		return (-1);
	else if (c > 0xFFFF)
		cpt += 4;
	else if (c > 0x7FF)
		cpt += 3;
	else if ((c > 0x7F && MB_CUR_MAX >= 2) || c > 0xFF)
		cpt += 2;
	else
		cpt++;
	return (cpt);
}
