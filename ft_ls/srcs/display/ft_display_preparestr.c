/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_preparestr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:01:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:12:48 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** La valeur initial de len n'est pas obtenue de facon aléatoire elle depends
** de l'observation de ls -l, et correspond aux schemas ci-dessous suivant si
** un minor ou un major sont définit.
*/

static int
	ft_count_strlen(t_disp *disp)
{
	int				len;

	len = 26;
	if (disp->major != 0 || disp->minor != 0)
	{
		len += 3;
		len += (ft_utils_nbweight(disp->major) + 1);
		len += (ft_utils_nbweight(disp->minor) + 1);
	}
	else
		len += (ft_utils_nbweight(disp->size));
	len += (ft_utils_nbweight(disp->mode));
	len += (ft_utils_nbweight(disp->nlink));
	len += (ft_utils_nbweight(disp->uid));
	len += (ft_utils_nbweight(disp->gid));
	return (len);
}

static void
	ft_display_preparestr_aux(t_disp *disp, size_t *count, char **str)
{
	if (disp->major != 0 || disp->minor != 0)
	{
		ft_putendl("\ncoucou");
		*count = ft_utils_pflag_d(str, disp->major + 1, *count);
		(*count) += ft_strcpy_x(&(*str)[*count], ",");
		*count = ft_utils_pflag_d(str, disp->minor + 1, *count);
	}
	else
		*count = ft_utils_pflag_d(str, disp->size, *count);
}

/*
** Prepare les chaines ci-dessous pour etre utilisé avec printf
** suivant si major et minor sont définit ou non.
** "%-s %d %-s  %-s  %d %s"
** "%-s %d %-s  %-s  %d,%d %s"
*/

extern char
	*ft_display_preparestr(t_disp *disp)
{
	int				str_len;
	char			*str;
	size_t			count;

	str_len = ft_count_strlen(disp);
	if (!(str = ft_strnew(str_len)))
		return (0);
	count = 0;
	count = ft_utils_pflag_s(&str, disp->mode, count);
	count += ft_strcpy_x(&str[count], " ");
	count = ft_utils_pflag_d(&str, disp->nlink, count);
	count += ft_strcpy_x(&str[count], " ");
	count = ft_utils_pflag_offs(&str, disp->uid, count);
	count += ft_strcpy_x(&str[count], "  ");
	count = ft_utils_pflag_offs(&str, disp->gid, count);
	count += ft_strcpy_x(&str[count], "  ");
	ft_display_preparestr_aux(disp, &count, &str);
	if (ft_param_get('T'))
		count += ft_strcpy_x(&str[count], " %24s ");
	else
		count += ft_strcpy_x(&str[count], " %-12s ");
	return (str);
}
