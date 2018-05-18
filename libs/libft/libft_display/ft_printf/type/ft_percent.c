/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:41:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:19:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_percent(uintmax_t val, t_skel **skel)
{
	t_list			*result;
	char			*str;

	val = 0;
	ft_setskel(skel, FT_DISPOSITION_SPE, " ", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "+", 0);
	ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
	ft_setskel(skel, FT_ACCURACY_SPE, "2", -1);
	if (!(str = ft_strdup("%")))
		return (0);
	result = ft_option(skel, str, val, ft_strlen(str) + 1);
	ft_strdel(&str);
	return (result);
}
