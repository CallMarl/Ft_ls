/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:59:58 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:35:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Verifie si la valeur int passé en parametre correspond à une majuscule et la
** transforme en minuscule.
*/

int		ft_tolower(int c)
{
	return ((ft_isupper(c)) ? c + 32 : c);
}
