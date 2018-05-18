/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:13:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:28:08 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Fonction de lancement de l'affichage de ft_ls
*/

extern int
	ft_display_ls(t_buff *buff)
{
	int				opt_l;
	int				opt_a;
	int				opt_1;

	opt_l = ft_param_get('l');
	opt_1 = ft_param_get('1');
	opt_a = ft_param_get('a');
	if (opt_l != 0 && opt_l > opt_1)
		return (ft_display_long(buff, opt_a));
	else if (opt_1 != 0 && opt_1 > opt_l)
		return (ft_display_short(buff, opt_a));
	else
		return (ft_display_column(buff, opt_a));
}
