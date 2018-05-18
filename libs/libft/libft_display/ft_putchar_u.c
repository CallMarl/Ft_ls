/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:09:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 15:33:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Affiche un caractere unicode de taille en octet inconnue et retourne sa
** taille.
*/

short			ft_putchar_u(char *c)
{
	short		i;
	short		size;
	char		*tmp;

	tmp = c;
	i = 0;
	size = -1;
	while (tmp[i] != 0 && size < 4)
	{
		size++;
		i++;
	}
	write(1, tmp++, size);
	return (size);
}
