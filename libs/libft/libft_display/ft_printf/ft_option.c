/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:25:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern t_list		*ft_option(t_skel **skel, char *nbr, intmax_t val, \
		size_t size)
{
	char			*sign;
	t_list			*result;
	char			*tmp;

	sign = ft_option_disp(skel, val);
	tmp = ft_option_accu2(skel, nbr, &size);
	if (tmp != 0)
	{
		result = ft_lstnew((void *)tmp, size);
		ft_strdel(&tmp);
	}
	else
		result = ft_lstnew((void *)nbr, size);
	result = ft_option_accu1(skel, result, sign);
	return (result);
}
