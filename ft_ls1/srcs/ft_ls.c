/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/04 12:22:10 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern int			ft_dir_launch(char *path, _Bool param_R)
{
	int				ret;

	ret = 1;
	(void)path;
	(void)param_R;
	return (ret);
}

/*
** Surcouche de la fonction main().
** Fonction de lancement du programme ft_ls.
*/

extern int			ft_ls(int argc, char **argv)
{
	int 			ret;
	int				cur;

	cur = ft_param_parse(argc, argv);
	ret = cur;
	if (ret > 0 && cur == argc - 1)
		ret = ft_dir_launch(".", ft_param_get('R'));
	else if (ret > 0)
	{
		while (cur < argc)
		{
			if ((ret = ft_dir_launch(argv[cur], ft_param_get('R'))) < 0)
				break ;
			cur++;
		}
	}
	if (ret < 0)
		ret = ft_error(ret);
	return (ret);
}
