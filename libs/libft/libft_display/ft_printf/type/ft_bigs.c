/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:24:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:47 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

static int			ft_check_accu(wchar_t *val, int accu)
{
	int		cpt;
	int		i;
	int		size;

	cpt = 0;
	i = 0;
	size = 0;
	while (cpt + size <= accu)
	{
		cpt += size;
		size = ft_charsize_u(val[i]);
		i++;
	}
	return (cpt);
}

static t_list		*ft_bigs_aux(void *val, t_skel **skel, char *tmp, int len)
{
	char			*str;
	int				accu;
	t_list			*result;

	str = 0;
	if ((size_t)(accu = ft_getskel_val(skel, FT_ACCURACY_SPE, "2"))
			<= ft_strlen(tmp) && accu != -1)
	{
		accu = ft_check_accu((wchar_t *)val, accu);
		str = ft_strsub(tmp, 0, accu);
	}
	else if (len != -1)
		str = ft_strdup(tmp);
	ft_setskel(skel, FT_ACCURACY_SPE, "2", -1);
	result = 0;
	if (str != 0)
	{
		result = ft_option(skel, str, 0, ft_strlen(str) + 1);
		ft_strdel(&str);
	}
	return (result);
}

extern t_list		*ft_bigs(void *val, t_skel **skel)
{
	char			*tmp;
	int				len;
	t_list			*result;

	ft_setskel(skel, FT_SIZE_SPE, "l", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	len = 0;
	tmp = 0;
	if ((wchar_t *)val == 0)
		tmp = ft_strdup("(null)");
	else
		len = ft_unicode_str((wchar_t *)val, &tmp);
	result = 0;
	if (tmp != 0)
		result = ft_bigs_aux(val, skel, tmp, len);
	ft_strdel(&tmp);
	return (result);
}
