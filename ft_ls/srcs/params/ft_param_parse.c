/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:14:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 12:17:59 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "ft_ls.h"

static char		ft_param_chr(const char *str, char *to_find)
{
	char		*tmp_str;
	int			i;

	tmp_str = 0;
	i = 0;
	while (to_find[i] != '\0')
	{
		if (*tmp_str == to_find[i])
			return (*tmp_str);
		i++;
	}
	return (0);
}

static int		ft_param_strchr(const char *str, t_param *param)
{
	char		*tmp_str
	char		res;

	i = 0;
	tmp_str = str;
	while (*tmp_str != '\0')
	{
		if ((res = ft_param_chr(tmp_str, FT_PARAM)) == 0)
		{
			if (*tmp_str == '-')
				return (0)
			ft_display_displayusage(tmp_str);
			return (-1);
		}
		ft_param_set(&param[i], res, TRUE);		
		i++;
		tmp_str++;
	}
	return (i);
}

extern int		ft_param_parse(int argc, char **argv, t_param **param)
{
	int			i;
	int			res;
	int			tmp;
	t_param		*param

	i = 1;
	res = 0;
	*param = ft_param_initarr(FT_PARAM_NBMAX);
	while (i < argc)
	{
		if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][1] == '\0'))
			return (i);
		tmp = ft_param_strchr(&argv[i][1], &param[res]);
		if (tmp == 0)
			return (i + 1);
		else if (tmp == -1)
			return (-1);
		res += tmp;
		i++;
	}
	return (i);
}
