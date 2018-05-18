/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:08:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:17:52 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_skel		**ft_size_spe(char *flag_cpy, int *size, t_skel **skel)
{
	if (*size > 0 && ((flag_cpy[*size] == 'h' && flag_cpy[*size - 1] == 'h') ||
			(flag_cpy[*size] == 'l' && flag_cpy[*size - 1] == 'l')))
	{
		ft_setskel(skel, FT_SIZE_SPE, &flag_cpy[*size - 1], 1);
		flag_cpy[(*size)--] = '\0';
		flag_cpy[(*size)] = '\0';
	}
	if (*size >= 0 && ft_setskel(skel, FT_SIZE_SPE, &flag_cpy[*size], 1))
		flag_cpy[(*size)] = '\0';
	return (skel);
}

static t_skel		**ft_accuracy2_spe(char *flag_cpy, int *size, t_skel **skel)
{
	int				i;

	ft_setupskel(skel, FT_ACCURACY_SPE, "2", ft_atoi(&flag_cpy[(*size) + 1]));
	i = 0;
	while (flag_cpy[*size + i] != '\0')
		flag_cpy[*size + i++] = '\0';
	while (*size >= 0 && ft_isdigit(flag_cpy[*size]))
		(*size)--;
	return (skel);
}

static t_skel		**ft_accuracy_spe(char *flag_cpy, int *size, t_skel **skel)
{
	int				i;

	if (*size >= 0 && ft_isdigit(flag_cpy[*size]))
	{
		while (*size >= 0 && ft_isdigit(flag_cpy[*size]))
			(*size)--;
		if (flag_cpy[*size] == '.')
			skel = ft_accuracy2_spe(flag_cpy, size, skel);
		ft_setupskel(skel, FT_ACCURACY_SPE, "1", \
				ft_atoi(&flag_cpy[(*size) + 1]));
		i = 1;
		if (flag_cpy[(*size) + 1] == '0')
			(*size)++;
		while (flag_cpy[*size + i] != '\0')
			flag_cpy[*size + i++] = '\0';
	}
	else if (*size >= 0 && flag_cpy[*size] == '.')
	{
		ft_setupskel(skel, FT_ACCURACY_SPE, "2", 0);
		flag_cpy[*size] = '\0';
	}
	return (skel);
}

static t_skel		**ft_disposition_spe(char *flag_cpy, int *size,\
		t_skel **skel)
{
	if (*size >= 0 && ft_setskel(skel, FT_DISPOSITION_SPE, &flag_cpy[*size], 1))
		flag_cpy[*size] = '\0';
	return (skel);
}

extern t_skel		**ft_analyze_flag(char *flag, int size, \
		t_skel **skel)
{
	char			*flag_cpy;

	flag_cpy = ft_strdup((flag + 1));
	if (size > 0)
		size--;
	if (ft_setskel(skel, FT_DISPLAY_SPE, &flag_cpy[size], 1))
	{
		flag_cpy[size] = '\0';
		size--;
	}
	while (size >= 0)
	{
		skel = ft_size_spe(flag_cpy, &size, skel);
		skel = ft_accuracy_spe(flag_cpy, &size, skel);
		skel = ft_disposition_spe(flag_cpy, &size, skel);
		size--;
	}
	ft_strdel(&flag_cpy);
	return (skel);
}
