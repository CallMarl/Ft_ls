/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_column.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:53:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 18:48:26 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ls.h"

static size_t		ft_display_getmaxlen(t_buff *buff)
{
	size_t			i;
	size_t			len;
	size_t			max_len;

	i = 0;
	len = 0;
	max_len = 0;
	while (i < buff->cr)
	{
		len = ft_strlen(((t_file *)buff->buff)[i].name);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

/*
** Bonus display fonction
*/

extern int			ft_display_column(t_buff *buff, int pa)
{
	size_t			max_len;
	char			*str;
	size_t			size;
	char			*name;

	max_len = ft_display_getmaxlen(buff);
	size = 4 + ft_nbweight(max_len);
	if (!(str = ft_strnew(size)))
		return (-1);
	size = 0;
	size = ft_insert_offset_str(&str, max_len, size);
	size = ft_strcpy_x(&str[size], " ");
	size = 0;
	while (size < buff->cr)
	{
		name = (&((t_file *)buff->buff)[size])->name;
		if (name[0] != '.')
			ft_printf(str, name);
		else if (pa != 0)
			ft_printf(str, name);
		size++;
	}
	ft_putchar('\n');
	return (1);
}
