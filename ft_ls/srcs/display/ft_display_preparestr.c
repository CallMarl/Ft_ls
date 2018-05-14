/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_preparestr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:01:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 17:26:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** La valeur initial de len n'est pas obtenue de facon aléatoire elle depends
** de l'observation de ls -l, et correspond aux schemas ci-dessous suivant si
** un minor ou un major sont définit.
*/
static int			ft_count_strlen(t_disp *disp)
{
	int				len;

	len = 23;
	if (disp->major != 0 || disp->minor != 0)
	{
		len += 3;
		len += (ft_nbweight(disp->major) + 1);
		len += (ft_nbweight(disp->minor) + 1);
	}
	else
		len += (ft_nbweight(disp->size));
	len += (ft_nbweight(disp->mode));
	len += (ft_nbweight(disp->nlink));
	len += (ft_nbweight(disp->uid));
	len += (ft_nbweight(disp->gid));
	return (len);
}

/*
** insert un %s avec une valeur dispval dans str. Par exemple %10s.
*/

static int			ft_insert_basic_str(char **str, int dispval, int count)
{
	char			*tmp;

	count += ft_strcpy_x(&(*str)[count], "%");
	tmp = ft_insertnbr(&(*str)[count], dispval);
	count += ((int)tmp - (int)&(*str)[count]);
	count += ft_strcpy_x(&(*str)[count], "s");
	return (count);
}

/*
** insert un %-s avec une valeur dispval dans str. Par exemple %-10s.
*/

extern int			ft_insert_offset_str(char **str, int dispval, int count)
{
	char			*tmp;

	count += ft_strcpy_x(&(*str)[count], "%-");
	tmp = ft_insertnbr(&(*str)[count], dispval);
	count += ((int)tmp - (int)&(*str)[count]);
	count += ft_strcpy_x(&(*str)[count], "s");
	return (count);
}

static int			ft_insert_basic_digit(char **str, int dispval, int count)
{
	char			*tmp;

	count += ft_strcpy_x(&(*str)[count], "%");
	tmp = ft_insertnbr(&(*str)[count], dispval);
	count += ((int)tmp - (int)&(*str)[count]);
	count += ft_strcpy_x(&(*str)[count], "d");
	return (count);
}

/*
** Prepare les chaines ci-dessous pour etre utilisé avec printf
** suivant si major et minor sont définit ou non.
** "%-s %d %-s  %-s  %d %s"
** "%-s %d %-s  %-s  %d,%d %s"
*/
extern int			ft_display_preparestr(t_disp *disp, char **str)
{
	int				str_len;
	int				count;

	str_len = ft_count_strlen(disp);
	if (!(*str = ft_strnew(str_len)))
		return (-1);
	count = 0;
	count = ft_insert_basic_str(str, disp->mode, count);
	count += ft_strcpy_x(&(*str)[count], " ");
	count = ft_insert_basic_digit(str, disp->nlink, count);
	count += ft_strcpy_x(&(*str)[count], " ");
	count = ft_insert_offset_str(str, disp->uid, count);
	count += ft_strcpy_x(&(*str)[count], "  ");
	count = ft_insert_offset_str(str, disp->gid, count);
	count += ft_strcpy_x(&(*str)[count], "  ");
	if (disp->major != 0 || disp->minor != 0)
	{
		count = ft_insert_basic_digit(str, disp->major + 1, count);
		count += ft_strcpy_x(&(*str)[count], ",");
		count = ft_insert_basic_digit(str, disp->minor + 1, count);
	}
	else
		count = ft_insert_basic_digit(str, disp->size, count);
	count += ft_strcpy_x(&(*str)[count], " %s ");
	return (1);
}
