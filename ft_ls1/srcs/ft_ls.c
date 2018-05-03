/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 19:19:33 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
static int			ft_ls_init(int argc, char **argv, t_path **path)
{
	int				ret;

	ret = 1;
	return (ret);
}
*/
/*
** Surcouche de la fonction main().
** Fonction de lancement du programme ft_ls.
*/

extern int			ft_ls(int argc, char **argv)
{
	int 			ret;
	t_param			*param;
//	t_path			*path;

	ret = 1;

	if (ret < 0)
		ft_error(ret);
	(void)param;
	(void)argc;
	(void)argv;
	return (ret);
}
