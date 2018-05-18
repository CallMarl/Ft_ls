/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_uchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:14 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:24:06 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d' un unsigned char en binaire
*/

void		ft_putbit_uchar(unsigned char val)
{
	ft_putbit((void *)&val, sizeof(unsigned char));
}
