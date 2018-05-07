/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 19:00:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"


/*
** Surcouche de la fonction main().
** Fonction de lancement du programme ft_ls.
*/

extern int			ft_ls(int argc, char **argv)
{
	int 			ret;
	int				cur;
	t_list			*buff;

	cur = ft_param_parse(argc, argv);
	ret = cur;
	buff = 0;
	if (ret > 0)
	{	
		if (cur < argc)
		{
			ret = ft_ls_args(&argv[cur], argc - cur, &buff);
		}
		else
			ret = ft_ls_noargs(".", ft_param_get('R'));
	}
	if (ret < 0)
		ret = ft_error(ret);
	return (ret);
}
