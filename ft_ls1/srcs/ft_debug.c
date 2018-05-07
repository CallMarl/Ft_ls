/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:40 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 17:08:30 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern t_param		g_param[];

extern void			ft_debug_buff(t_buff *buff)
{
	size_t			i;
	t_file			*file;

	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		ft_putstr("file name : ");
		ft_putendl(file->name);
		ft_putstr("file mode : ");
		ft_putnbr(file->stat.st_mode);
		ft_putendl("");
		i++;
	}
}

/*
** Fonction de debugging pour afficher les paramettre inséré dans la commande
** ft_ls.
*/

extern void			ft_debug_param(void)
{
	int				i;

	i = 0;
	while (g_param[i].key != 0)
	{
		ft_putstr("key => ");
		ft_putchar(g_param[i].key);
		ft_putstr(", value => ");
		(g_param[i].val == 1) ? ft_putendl("True") : ft_putendl("False");
		i++;
	}
}
