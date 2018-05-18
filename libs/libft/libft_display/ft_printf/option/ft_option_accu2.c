/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_accu2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:43:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:20:06 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"

extern char			*ft_option_accu2(t_skel **skel, char *nbr, size_t *size)
{
	char			*str;
	size_t			tmp;
	size_t			accu;

	accu = (size_t)ft_getskel_val(skel, FT_ACCURACY_SPE, "2");
	if ((int)accu > 0)
	{
		ft_setskel(skel, FT_DISPOSITION_SPE, "0", 0);
		ft_setskel(skel, FT_DISPOSITION_SPE, "#", 0);
		if (accu >= *size)
		{
			tmp = (*size) - 1;
			*size = accu + 1;
			str = ft_strnew_c(*size, '0');
			while (tmp > 0)
				str[--accu] = nbr[--tmp];
			return (str);
		}
	}
	return (0);
}
