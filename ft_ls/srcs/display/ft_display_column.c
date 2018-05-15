/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_column.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:53:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/15 11:34:24 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/ioctl.h>
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

static size_t		ft_compt_nb_column(void)
{
	struct winsize ws;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
		return (0);
	return ((size_t)ws.ws_col);
}

static void			ft_putblanck(size_t size)
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

static void			ft_display_column_aux(t_buff *buff, size_t max_len, \
		size_t nb_file, int pa)
{
	size_t			i;
	size_t			y;
	t_file			*file;

	y = 0;
	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.' || pa != 0)
		{
			ft_display_file(file);
			ft_putblanck(max_len - ft_strlen(file->name) + 1);
			y++;
		}
		if (y == nb_file)
		{
			ft_putchar('\n');
			y = 0;
		}
		i++;
	}
	ft_putchar('\n');
}

/*
** Bonus display fonction
*/

extern int			ft_display_column(t_buff *buff, int pa)
{
	size_t			max_len;
	size_t			column;

	max_len = ft_display_getmaxlen(buff);
	column = ft_compt_nb_column();
	ft_display_column_aux(buff, max_len, column / (max_len + 1), pa);
	return (1);
}
