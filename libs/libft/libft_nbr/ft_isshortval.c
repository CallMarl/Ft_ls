/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isshortval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:47:40 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 15:00:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>

int				ft_isshortval(uintmax_t val)
{
	uintmax_t		mask;

	mask = (uintmax_t)USHRT_MAX;
	if ((val & mask) > USHRT_MAX)
		return (0);
	return (1);
}
