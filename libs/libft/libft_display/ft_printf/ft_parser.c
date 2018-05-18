/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:58:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:16 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#define FT_SPETYPE_SIZE 6

static void			ft_initialize_flag(char **special)
{
	special[0] = "#0-+ ";
	special[1] = "0123456789";
	special[2] = ".";
	special[3] = "0123456789";
	special[4] = "hljz";
	special[5] = "sSpdDioOuUxXcCi%";
	special[FT_SPETYPE_SIZE] = 0;
}

static int			ft_size_flag(char *str, char **special)
{
	int				i;
	int				j;

	i = 1;
	str++;
	while (*str)
	{
		j = 0;
		while (j < FT_SPETYPE_SIZE)
		{
			if (ft_strchr(special[j], *str) != 0)
				break ;
			j++;
		}
		i++;
		if (j >= FT_SPETYPE_SIZE - 1)
			return (i);
		str++;
	}
	return (i);
}

static void			ft_sanitalize_flag(char **flag, char **special, int *size)
{
	int				i;
	int				j;
	char			*flag_cpy;

	i = 0;
	flag_cpy = *flag + 1;
	while (*flag_cpy)
	{
		if (ft_strchr(special[i], *flag_cpy) || i == 5)
			flag_cpy++;
		else
		{
			j = i - 1;
			while (j >= 0)
			{
				if (ft_strchr(special[i], *flag_cpy))
				{
					ft_strsup(flag_cpy, 0);
					(*size)--;
				}
				j--;
			}
			i++;
		}
	}
}

extern int			ft_parse_flag(char **str, char **flag)
{
	int				size;
	char			*special[FT_SPETYPE_SIZE];

	ft_initialize_flag(special);
	while (**str)
	{
		if (**str == '%')
		{
			size = ft_size_flag((*str), special);
			*flag = ft_strsub((*str), 0, size);
			ft_sanitalize_flag(flag, special, &size);
			return (size);
		}
		(*str)++;
	}
	return (0);
}
