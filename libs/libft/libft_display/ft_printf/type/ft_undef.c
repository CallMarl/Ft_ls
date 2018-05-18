/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undef.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:27:57 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:32 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_list			*ft_undef(t_skel **skel, char *flag, int size)
{
	char		*str;
	int			undef;
	t_list		*result;

	str = "";
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	if ((undef = ft_getskel_val(skel, FT_DISPLAY_SPE, "undef")) == 1)
		str = ft_strsub(flag, size - 1, 1);
	result = ft_option(skel, str, 0, ft_strlen(str) + 1);
	if (undef == 1)
		ft_strdel(&str);
	return (result);
}
