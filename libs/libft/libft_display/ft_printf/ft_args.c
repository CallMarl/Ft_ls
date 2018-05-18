/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:55:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:17:56 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_args(va_list ap, t_skel **skel, char *flag, int size)
{
	t_list			*result;
	char			*skel_val;

	skel_val = ft_getskel_spe(skel, FT_DISPLAY_SPE);
	if (skel_val != 0)
	{
		if (ft_strcmp(skel_val, "%") == 0)
			return (ft_percent(0, skel));
		else if (ft_args_imt(ap, skel, skel_val, &result))
			return (result);
		else if (ft_args_lgd(ap, skel, skel_val, &result))
			return (result);
		else if (ft_args_ptr(ap, skel, skel_val, &result))
			return (result);
	}
	return (ft_undef(skel, flag, size));
}
