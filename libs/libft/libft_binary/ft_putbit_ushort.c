/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_ushort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:33 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:24:24 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d' un unsigned short en binaire
*/

void		ft_putbit_ushort(unsigned short val)
{
	ft_putbit((void *)&val, sizeof(unsigned short));
}
