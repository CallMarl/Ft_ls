/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:42:10 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 14:59:07 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>

int				ft_ischarval(uintmax_t val)
{
	uintmax_t		mask;

	mask = (uintmax_t)UCHAR_MAX;
	if ((val & mask) > UCHAR_MAX)
		return (0);
	return (1);
}
