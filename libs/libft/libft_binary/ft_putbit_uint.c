/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:20 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:24:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la valeur d' un unsigned int en binaire
*/

void		ft_putbit_uint(unsigned int val)
{
	ft_putbit((void *)&val, sizeof(unsigned int));
}
