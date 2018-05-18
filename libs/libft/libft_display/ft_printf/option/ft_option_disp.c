/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:47:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:20:10 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern char			*ft_option_disp(t_skel **skel, intmax_t val)
{
	char			*sign;

	sign = (val < 0) ? "-" : "+";
	if (ft_getskel_val(skel, FT_DISPOSITION_SPE, "+") == 0 && sign[0] != '-')
		sign = " ";
	if (ft_getskel_val(skel, FT_DISPOSITION_SPE, " ") == 0
			&& sign[0] != '-' && sign[0] != '+')
		sign = "";
	if (ft_getskel_val(skel, FT_DISPOSITION_SPE, "#") == 1)
	{
		if (ft_getskel_val(skel, FT_DISPLAY_SPE, "x")
				|| ft_getskel_val(skel, FT_DISPLAY_SPE, "p"))
			sign = "0x";
		else if (ft_getskel_val(skel, FT_DISPLAY_SPE, "X"))
			sign = "0X";
		else
			sign = "0";
	}
	return (sign);
}
