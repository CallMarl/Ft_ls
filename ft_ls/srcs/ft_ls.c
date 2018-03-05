/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:04:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 13:01:04 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern int			ft_ls(int argc, char **argv)
{
	t_param			*param;

	param = 0;
	if ((ft_param_parse(argc, argv, &param)) == -1)
		return (-1);
	ft_param_display(param, 0);
	return (0);
}
