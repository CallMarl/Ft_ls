/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:50:39 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:32:46 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Verifie si la valeur int passé en parametre correspond à un caractere
** alphabetique.
*/

int		ft_isalpha(int c)
{
	return ((ft_isupper(c) || ft_islower(c)) ? 1 : 0);
}
