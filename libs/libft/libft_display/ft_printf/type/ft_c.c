/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:55:19 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:53 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_c(uintmax_t val, t_skel **skel)
{
	char			*nbr;
	t_list			*result;

	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	ft_setskel(skel, FT_ACCURACY_SPE, "2", -1);
	if (ft_getskel_val(skel, FT_SIZE_SPE, "l") == 1)
		return (ft_bigc(val, skel));
	nbr = ft_strnew(sizeof(unsigned char));
	nbr[0] = (unsigned char)val;
	result = 0;
	if (nbr != 0)
	{
		result = ft_option(skel, nbr, 0, sizeof(unsigned char) + 1);
		ft_strdel(&nbr);
	}
	return (result);
}
