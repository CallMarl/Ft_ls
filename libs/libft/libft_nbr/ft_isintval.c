/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isintval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:18:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/28 15:48:55 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>

int				ft_isintval(uintmax_t val)
{
	uintmax_t		mask;

	mask = (uintmax_t)UINT_MAX;
	if ((val & mask) > UINT_MAX)
		return (0);
	return (1);
}
