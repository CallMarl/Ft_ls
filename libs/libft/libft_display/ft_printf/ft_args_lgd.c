/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_lgd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:11:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:03 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#define FT_SPELGD_SIZE 5

static t_lgd		*ft_inidisplay_lgd(void)
{
	static t_lgd	lgd[] = {
		{"f", &ft_f}, {"e", &ft_e}, {"E", &ft_e}, {"g", &ft_g}, {"G", &ft_g}
	};

	return (lgd);
}

static t_list		*(*ft_calllgd_fct(char *skel_val, \
			t_lgd *lgd))(long double, t_skel **)
{
	int				i;
	int				call_size;

	i = 0;
	call_size = FT_SPELGD_SIZE;
	while (i < call_size)
	{
		if (ft_strcmp(skel_val, lgd[i].type) == 0)
			return (lgd[i].pfct);
		i++;
	}
	return (0);
}

extern int			ft_args_lgd(va_list ap, t_skel **skel, char *skel_val,\
		t_list **result)
{
	t_lgd			*lgd;
	t_list			*(*pfct)(long double, t_skel **);

	lgd = ft_inidisplay_lgd();
	if ((pfct = ft_calllgd_fct(skel_val, lgd)))
	{
		*result = pfct(va_arg(ap, long double), skel);
		return (1);
	}
	return (0);
}
