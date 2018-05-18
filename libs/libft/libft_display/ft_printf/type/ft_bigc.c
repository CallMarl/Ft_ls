/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:24:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:36 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_bigc(uintmax_t val, t_skel **skel)
{
	char			*nbr;
	t_list			*result;

	ft_setskel(skel, FT_SIZE_SPE, "l", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	ft_setskel(skel, FT_ACCURACY_SPE, "2", -1);
	nbr = ft_unicode((wchar_t)val);
	result = 0;
	if (nbr != 0)
	{
		result = ft_option(skel, nbr, 0, ft_charsize_u((wchar_t)val) + 1);
		ft_strdel(&nbr);
	}
	return (result);
}
