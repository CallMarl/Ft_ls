/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_imt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:54:05 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:17:59 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"
#define FT_SPEIMT_SIZE 11

static t_imt		*ft_inidisplay_imt(void)
{
	static t_imt	imt[] = {
		{"d", &ft_d}, {"D", &ft_bigd}, {"u", &ft_u},
		{"U", &ft_u}, {"x", &ft_x}, {"X", &ft_bigx},
		{"i", &ft_i}, {"o", &ft_o}, {"O", &ft_bigo},
		{"c", &ft_c}, {"C", &ft_bigc}
	};

	return (imt);
}

static t_list		*(*ft_callimt_fct(char *skel_val,\
			t_imt *imt))(uintmax_t val, t_skel **skel)
{
	int				i;
	int				call_size;

	i = 0;
	call_size = FT_SPEIMT_SIZE;
	while (i < call_size)
	{
		if (ft_strcmp(skel_val, imt[i].type) == 0)
			return (imt[i].pfct);
		i++;
	}
	return (0);
}

extern int			ft_args_imt(va_list ap, t_skel **skel, char *skel_val,\
		t_list **result)
{
	t_imt			*imt;
	t_list			*(*pfct)(uintmax_t val, t_skel **skel);

	imt = ft_inidisplay_imt();
	if ((pfct = ft_callimt_fct(skel_val, imt)))
	{
		*result = pfct(va_arg(ap, uintmax_t), skel);
		return (1);
	}
	return (0);
}
