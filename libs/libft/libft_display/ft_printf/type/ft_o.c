/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:56:13 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_o(uintmax_t val, t_skel **skel)
{
	char			*nbr;
	t_list			*result;
	int				accu2;

	nbr = "";
	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	accu2 = ft_getskel_val(skel, FT_ACCURACY_SPE, "2");
	ft_option_usize(&val, ft_getskel_spe(skel, FT_SIZE_SPE));
	if (val == 0 && accu2 != 0)
		ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	if (accu2 == 0)
		ft_setskel(skel, FT_DISPOSITION_SPE, "0", 0);
	if (!(accu2 == 0 && val == 0))
		nbr = ft_itoau_base((uintmax_t)val, "01234567");
	if (accu2 >= (int)ft_strlen(nbr) && accu2 != 0)
		ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	result = ft_option(skel, nbr, 0, ft_strlen(nbr) + 1);
	if (!(accu2 == 0 && val == 0))
		ft_strdel(&nbr);
	return (result);
}
