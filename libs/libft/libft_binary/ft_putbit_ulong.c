/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_ulong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:27 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:24:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d' un unsigned long en binaire
*/

void		ft_putbit_ulong(unsigned long val)
{
	ft_putbit((void *)&val, sizeof(unsigned long));
}
