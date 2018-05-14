/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:53:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 11:57:08 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "ft_ls.h"

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

extern void			ft_display_dir(t_buff *buff, int pl, int p1, int pa)
{
	size_t			i;
	t_file			*file;
	t_disp			disp;
	char			*str;

	i = 0;
	str = 0;
	if (pl != 0 && pl > p1)
	{
		ft_disp_init(&disp);
		ft_display_prepare(buff, &disp);
		ft_display_preparestr(&disp, &str);
		ft_putstr(str);
	}
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		ft_display_file(file, pl , p1, pa);
		i++;
	}
	ft_putchar('\n');
}
