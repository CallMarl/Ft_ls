/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islongval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:43:02 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 14:59:48 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>

int				ft_islongval(uintmax_t val)
{
	uintmax_t		mask;

	mask = (uintmax_t)ULONG_MAX;
	if ((val & mask) > ULONG_MAX)
		return (0);
	return (1);
}
