/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:13:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/13 19:07:22 by pprikazs         ###   ########.fr       */
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
** Structure qui indique la largeur des colone pour chacun des précision
*/

static	void		ft_disp_init(t_disp *disp)
{
	disp->mode = 11;
	disp->nlink = 0;
	disp->uid = 0;
	disp->gid = 0;
	disp->size = 0;
	disp->major = 0;
	disp->minor = 0;
}

/*
** Affichage basic des dossier comme avec ls -1
*/

static void			ft_display_basic(t_buff *buff, int pl, int p1)
{
	size_t			i;
	int				pa;
	t_file			*file;
	t_disp			disp;

	i = 0;
	pa = ft_param_get('a');
	if (pl != 0 && pl > p1)
	{
		ft_disp_init(&disp);
		ft_display_prepare(buff, &disp);
	}
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
