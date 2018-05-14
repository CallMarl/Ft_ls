/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:53:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 12:38:42 by pprikazs         ###   ########.fr       */
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

static void			ft_display_long_aux(t_file *file)
{
	(void)file;
}

/*
** Affichage basic des dossier comme avec ls -1
*/

extern void			ft_display_long(t_buff *buff, int pa)
{
	size_t			i;
	t_file			*file;
	t_disp			disp;
	char			*str;

	str = 0;
	ft_disp_init(&disp);
	ft_display_prepare(buff, &disp, pa);
	ft_display_preparestr(&disp, &str);
	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.')
			ft_display_long_aux(file);
		else if (pa != 0)
			ft_display_long_aux(file);
		i++;
	}
	ft_putchar('\n');
}
