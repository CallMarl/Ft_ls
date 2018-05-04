/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:12:04 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/04 12:16:12 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Ce fichier utilise la variable globale g_param, voir srcs/ft_global.c
*/

extern t_param		g_param[];

/*
** Aucun cas d'erreur n'est retourné dans cette fonction, un appel a un 
** paramettre qui n'existe pas retournera 0.
*/

extern _Bool		ft_param_get(char param)
{
	int				i;

	i = 0;
	while (g_param[i].key != 0)
	{
		if (param == g_param[i].val)
			return (g_param[i].val);
	}
	return (0);
}
