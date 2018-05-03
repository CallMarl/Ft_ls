/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:06:04 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 16:13:36 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int			main(int argc, char **argv)
{
	int		ret;

	ret = ft_ls(argc, argv);
	if (ret == 0)
		ft_putstr("Error");
	return (0);
}
