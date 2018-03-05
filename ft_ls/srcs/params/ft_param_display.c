/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:13:01 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 12:17:52 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void		ft_param_display(t_param *param, int state)
{
	int		max;
	int		i;

	if (param != 0)
	{
		max = FT_PARAM_NBMAX;
		if (state > 0)
			max = ft_param_size(param);
		i = 0;
		while (i < max)
		{
			ft_putstr("key : ");
			ft_putchar(param[i]->key);
			ft_putstr(" ==> ");
			ft_putnbr(param[i]->key);
			ft_putchar('\n');
			ft_putstr("val : ");
			ft_putnbr(param[i]->val);
			ft_putendl("\n");
			i++;
		}
	}
}

extern void		ft_param_displayusage(char param)
{
	ft_putstr(FT_PARAM_PRGNAME);
	ft_putstr(": illegal option -- ");
	ft_putchar(param);
	ft_putchar('\n');
	ft_putstr("usage: ");
	ft_putstr(FT_PARAM_PRGNAME);
	ft_putstr("[-");
	ft_putstr(FT_PARAM);
	ft_putstr("]");
	ft_param_displayuagse(bad_param);
	ft_putstr("[file ...]\n");
}
