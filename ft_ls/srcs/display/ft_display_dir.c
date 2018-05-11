/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:13:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/11 19:51:28 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Bonus display fonction
*/

static void			ft_display_column(t_buff *buff)
{
	(void)buff;
}

/*
** Affichage basic des dossier comme avec ls -1
*/

static void			ft_display_basic(t_buff *buff, int pl, int p1)
{
	size_t			i;
	int				pa;
	t_file			*file;

	i = 0;
	pa = ft_param_get('a');
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		ft_display_file(file, pl , p1, pa);
		i++;
	}
	ft_putchar('\n');
}

extern void			ft_display_dir(t_buff *buff)
{
	int				pl;
	int				p1;

	pl = ft_param_get('l');
	p1 = ft_param_get('1');
	if (pl != 0 || p1 != 0)
		ft_display_basic(buff, pl, p1);
	else
		ft_display_column(buff);
}
