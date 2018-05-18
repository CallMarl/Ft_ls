/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_accu1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:27:07 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:22:12 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"

static char			*ft_zero_aux(char *sign, size_t size)
{
	int				i;
	size_t			len;
	char			*str;

	len = 0;
	if (sign)
		len = ft_strlen(sign);
	if (size > len)
	{
		i = 0;
		str = ft_strnew_c(size, '0');
		while (*sign)
			str[i++] = *sign++;
	}
	else
		str = ft_strdup(sign);
	return (str);
}

static char			*ft_space_aux(char *sign, size_t size)
{
	size_t			len;
	char			*str;

	len = 0;
	if (sign)
		len = ft_strlen(sign);
	if (size > len)
	{
		str = ft_strnew_c(size, ' ');
		while (*sign)
		{
			str[size - len] = *sign++;
			len--;
		}
	}
	else
		str = ft_strdup(sign);
	return (str);
}

static t_list		*ft_minus_aux(char *sign, size_t size, t_list *result)
{
	char			*str;

	if (sign[0] != '\0')
	{
		ft_lstpushf(&result, ft_lstnew((void *)sign, ft_strlen(sign) + 1));
		size -= ft_strlen(sign);
	}
	if (size < 2147483648)
	{
		str = ft_strnew_c(size, ' ');
		ft_lstpushb(&result, ft_lstnew((void *)str, size + 1));
		ft_strdel(&str);
	}
	return (result);
}

extern t_list		*ft_option_accu1(t_skel **skel, t_list *result, char *sign)
{
	char			*str;
	size_t			size;
	int				tmp;
	int				accu;

	accu = ft_getskel_val(skel, FT_ACCURACY_SPE, "1");
	tmp = 0;
	if (accu != -1)
		tmp = (accu - result->size + 1);
	if (tmp < 0)
		tmp = -tmp;
	if ((size_t)ft_getskel_val(skel, FT_ACCURACY_SPE, "1") <
			result->size)
		tmp = 0;
	size = tmp;
	if (ft_getskel_val(skel, FT_DISPOSITION_SPE, "-") || size <= 0)
		return (ft_minus_aux(sign, size, result));
	if (ft_getskel_val(skel, FT_DISPOSITION_SPE, "0"))
		str = ft_zero_aux(sign, size);
	else
		str = ft_space_aux(sign, size);
	ft_lstpushf(&result, ft_lstnew((void *)str, ft_strlen(str) + 1));
	ft_strdel(&str);
	return (result);
}
