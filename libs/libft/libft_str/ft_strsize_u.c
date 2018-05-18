/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsize_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:15:23 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:35:24 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la taille en octet d'une chaine de caractere.
*/

int			ft_strsize_u(wchar_t *str)
{
	int				i;
	int				tmp;
	int				cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		tmp = ft_charsize_u(str[i]);
		if (tmp == -1)
			return (-1);
		cpt += tmp;
		i++;
	}
	return (cpt);
}
