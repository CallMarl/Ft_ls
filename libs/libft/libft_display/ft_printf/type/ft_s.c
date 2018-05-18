/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:56:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:26 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_s(void *val, t_skel **skel)
{
	char			*tmp;
	char			*str;
	int				accu;
	t_list			*result;

	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	if (ft_getskel_val(skel, FT_SIZE_SPE, "l") == 1)
		return (ft_bigs(val, skel));
	tmp = (char *)val;
	if (tmp == 0)
		tmp = "(null)";
	if ((size_t)(accu = ft_getskel_val(skel, FT_ACCURACY_SPE, "2")) <
			ft_strlen(tmp) && accu != -1)
		str = ft_strsub(tmp, 0, accu);
	else
		str = ft_strdup(tmp);
	ft_setskel(skel, FT_ACCURACY_SPE, "2", -1);
	if (str == 0)
		return (0);
	result = ft_option(skel, str, 0, ft_strlen(str) + 1);
	ft_strdel(&str);
	return (result);
}
