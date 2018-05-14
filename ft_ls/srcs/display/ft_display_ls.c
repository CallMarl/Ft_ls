/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:13:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 12:49:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Bonus display fonction
*/

static void			ft_display_column(t_buff *buff, int pa)
{
	(void)buff;
	(void)pa;
}

extern void			ft_display_ls(t_buff *buff)
{
	int				pl;
	int				p1;
	int				pa;

	pl = ft_param_get('l');
	p1 = ft_param_get('1');
	pa = ft_param_get('a');
	if (pl != 0 && pl > p1)
		ft_display_long(buff, pa);
	else if (p1 != 0 && p1 > pl)
		ft_display_short(buff, pa);
	else
		ft_display_column(buff, pa);
}
