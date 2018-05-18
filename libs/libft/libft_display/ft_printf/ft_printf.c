/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:59:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/24 11:22:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static t_list			*ft_printf_iniflag(va_list ap, char *flag, int size)
{
	t_list		*result;
	t_skel		**skel;

	result = 0;
	if (size >= 1)
	{
		skel = ft_initialize_skel(flag, size);
		if (!(result = ft_args(ap, skel, flag, size)))
		{
			ft_strdel(&flag);
			return (0);
		}
	}
	if (result != 0)
		return (result);
	return (0);
}

static int				ft_printf_inicpy(t_list **buff, char *cpy, int diff)
{
	if (!(cpy = ft_strsub(cpy, 0, diff)))
		return (0);
	ft_lstpushb(buff, ft_lstnew(cpy, ft_strlen(cpy) + 1));
	ft_strdel(&cpy);
	return (1);
}

static int				ft_printf_aux(char *str, va_list ap, t_list **buff)
{
	int				size;
	char			*cpy;
	char			*flag;
	t_list			*result;

	size = 0;
	cpy = 0;
	while (*str)
	{
		cpy = str;
		size = ft_parse_flag(&str, &flag);
		if (size != 0)
		{
			if (!(result = ft_printf_iniflag(ap, flag, size)))
				return (0);
			if (!(ft_printf_inicpy(buff, cpy, str - cpy)))
				return (0);
			ft_lstpushb(buff, result);
		}
		else
			ft_lstpushb(buff, ft_lstnew(cpy, ft_strlen(cpy) + 1));
		ft_strdel(&flag);
		str += (size);
	}
	return (1);
}

extern int				ft_printf(char *str, ...)
{
	va_list			ap;
	t_list			*buff;
	size_t			size;

	buff = 0;
	if (*str == 0)
		return (0);
	va_start(ap, str);
	size = 0;
	if (!(ft_printf_aux(str, ap, &buff)))
	{
		if (buff)
		{
			size = ft_lstiter_andsum(buff, &ft_displaybuff);
			ft_lstdel(&buff, &ft_memdel_size);
		}
		va_end(ap);
		return (-1);
	}
	if (buff)
		size = ft_lstiter_andsum(buff, &ft_displaybuff);
	ft_lstdel(&buff, &ft_memdel_size);
	va_end(ap);
	return ((int)size);
}
