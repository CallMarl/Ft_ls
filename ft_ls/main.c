/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:07:38 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/03 18:08:48 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int			main(int argc, char **argv)
{
	int		ret;

	ret = ft_ls(argc, argv);
	(void)argc;
	(void)argv;
	return (ret);
}
