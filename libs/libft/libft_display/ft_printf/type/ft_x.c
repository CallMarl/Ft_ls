/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:56:48 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:36 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_x(uintmax_t val, t_skel **skel)
{
	char			*nbr;
	t_list			*result;

	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	if (val == 0)
		ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	ft_option_usize(&val, ft_getskel_spe(skel, FT_SIZE_SPE));
	nbr = "";
	if (!(ft_getskel_val(skel, FT_ACCURACY_SPE, "2") == 0 && val == 0))
	{
		if (!(nbr = ft_itoau_base((uintmax_t)val, "0123456789abcdef")))
			return (0);
		result = ft_option(skel, nbr, 0, ft_strlen(nbr) + 1);
		ft_strdel(&nbr);
	}
	else
		result = ft_option(skel, nbr, 0, ft_strlen(nbr) + 1);
	return (result);
}
