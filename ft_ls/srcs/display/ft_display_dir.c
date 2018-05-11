/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:13:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/11 19:05:34 by pprikazs         ###   ########.fr       */
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

static void			ft_display_basic(t_buff *buff)
{
	size_t			i;
	t_file			*file;

	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		ft_putendl(file->name);
		i++;
	}
	ft_putchar('\n');
}

/*
** Affichage détailler des dossier comme avec ls -l
*/

static void			ft_display_detail(t_buff *buff)
{
	(void)buff;
}

extern void			ft_display_dir(t_buff *buff)
{
	int				pl;
	int				p1;

	pl = ft_param_get('l');
	p1 = ft_param_get('1');
	if (pl != 0 && pl > p1)
		ft_display_detail(buff);
	else if (p1 != 0 && p1 > pl)
		ft_display_basic(buff);
	else
		ft_display_column(buff);
}
