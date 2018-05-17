/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_putblanck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:26:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 18:26:55 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern void			ft_utils_putblanck(size_t size)
{
	size_t			i;
	char			*str;

	i = 0;
	if (size < 3)
	{
		while (i++ < size)
			ft_putchar(' ');
	}
	else
	{
		if ((str = ft_strnew_c(size, ' ')))
		{
			ft_putstr(str);
			ft_strdel(&str);
		}
		else
		{
			while (i++ < size)
				ft_putchar(' ');
		}
	}
}
