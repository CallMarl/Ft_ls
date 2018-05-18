/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_column.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:53:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:26:01 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ls.h"

static size_t
	ft_display_getmaxlen(t_buff *buff)
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

static size_t
	ft_compt_nb_column(void)
{
	struct winsize ws;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
		return (0);
	return ((size_t)ws.ws_col);
}

static inline void
	ft_display_column_update(size_t *y, size_t nb_file, size_t *z)
{
	if (*y == nb_file)
	{
		ft_putchar('\n');
		*z = *y;
		*y = 0;
	}
}

static void
	ft_display_column_aux(t_buff *buff, size_t max_len, size_t nb_file, \
			int opt_a)
{
	size_t			i;
	size_t			y;
	size_t			z;
	t_file			*file;

	y = 0;
	i = 0;
	while (i < buff->cr)
	{
		z = 0;
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.' || opt_a != 0)
		{
			ft_display_file(file, 0);
			ft_utils_putblanck(max_len - ft_strlen(file->name) + 1);
			y++;
		}
		ft_display_column_update(&y, nb_file, &z);
		i++;
	}
	if (z != nb_file)
		ft_putchar('\n');
}

/*
** Bonus display fonction
*/

extern int
	ft_display_column(t_buff *buff, int opt_a)
{
	size_t			max_len;
	size_t			tmp;
	size_t			column;
	size_t			nb_file;

	max_len = ft_display_getmaxlen(buff);
	column = ft_compt_nb_column();
	tmp = 2;
	nb_file = 1;
	if (opt_a == 0)
		(buff->cr) -= 2;
	while ((max_len + 1) * (buff->cr / nb_file) > column && tmp < buff->cr)
	{
		if (buff->cr % tmp == 0 && tmp < buff->cr)
			nb_file = buff->cr / tmp;
		tmp++;
	}
	if (nb_file == 1 || (max_len + 1) * nb_file > column)
		nb_file = column / (max_len + 1);
	if (opt_a == 0)
		(buff->cr) += 2;
	ft_display_column_aux(buff, max_len, nb_file, opt_a);
	return (1);
}
