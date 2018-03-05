/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:04:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 12:18:04 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void			ft_ls(int argc, char **argv)
{
	t_param			*param;

	param = 0;
	if ((ft_param_parse(argc, argv, &param)) == -1)
		return (-1);
	ft_display_param(param, 0);
}
