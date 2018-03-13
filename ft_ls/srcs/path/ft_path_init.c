/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:36:11 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 15:48:01 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_path_init(int argc, char **argv, int cur, t_path *path)
{
	char	*no_args;

	if (cur < argc)
		path->path = &argv[cur];
	else if (cur == argc)
		path->path = 0;
	path->cur = 0;
	path->size = argc - size;
}
