/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:40 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 19:11:30 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern t_param		g_param[];

/*
** Fonction de debugging pour afficher les paramettre inséré dans la commande
** ft_ls.
*/

extern void			ft_display_param(void)
{
	while (g_param->key != 0)
	{
		ft_putstr("key => ");
		ft_putchar(g_param->key);
		ft_putstr(", value => ");
		(g_param->val == 1) ? ft_putendl("True") : ft_putendl("False");
	}
}
