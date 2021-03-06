/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:27:48 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:12:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "ft_ls.h"

extern int
	ft_display_short(t_buff *buff, int opt_a)
{
	size_t			i;
	t_file			*file;

	i = 0;
	while (i < buff->cr)
	{
		file = &((t_file *)buff->buff)[i];
		if (file->name[0] != '.' || opt_a != 0)
		{
			ft_display_file(file, 0);
			ft_putchar('\n');
		}
		i++;
	}
	return (1);
}
