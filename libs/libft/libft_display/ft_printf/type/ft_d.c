/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:55:29 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:57 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_d(uintmax_t val, t_skel **skel)
{
	char			*nbr;
	t_list			*result;
	int				accu2;

	ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	accu2 = ft_getskel_val(skel, FT_ACCURACY_SPE, "2");
	ft_option_size(&val, ft_getskel_spe(skel, FT_SIZE_SPE));
	if (accu2 >= 0)
		ft_setskel(skel, FT_DISPOSITION_SPE, "0", 0);
	nbr = "";
	if (!(accu2 == 0 && val == 0))
	{
		if (!(nbr = ft_itoa_base((intmax_t)val, "0123456789")))
			return (0);
		if (nbr[0] == '-')
			ft_memmove(nbr, (nbr + 1), ft_strlen(nbr) + 1);
		result = ft_option(skel, nbr, val, ft_strlen(nbr) + 1);
		ft_strdel(&nbr);
	}
	else
		result = ft_option(skel, nbr, val, ft_strlen(nbr) + 1);
	return (result);
}
