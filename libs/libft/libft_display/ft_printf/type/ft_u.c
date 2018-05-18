/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:56:39 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_u(uintmax_t val, t_skel **skel)
{
	char			*nbr;
	t_list			*result;
	int				accu2;

	accu2 = ft_getskel_val(skel, FT_ACCURACY_SPE, "2");
	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	if (accu2 >= ft_getskel_val(skel, FT_ACCURACY_SPE, "1"))
		ft_setskel(skel, FT_ACCURACY_SPE, "1", 0);
	if (ft_getskel_val(skel, FT_DISPLAY_SPE, "U") == 1)
		ft_setskel(skel, FT_SIZE_SPE, "l", 1);
	ft_option_usize(&val, ft_getskel_spe(skel, FT_SIZE_SPE));
	nbr = "";
	if (!(accu2 == 0 && val == 0))
	{
		if (!(nbr = ft_itoau_base((uintmax_t)val, "0123456789")))
			return (0);
		result = ft_option(skel, nbr, 0, ft_strlen(nbr) + 1);
		ft_strdel(&nbr);
	}
	else
		result = ft_option(skel, nbr, 0, ft_strlen(nbr) + 1);
	return (result);
}
