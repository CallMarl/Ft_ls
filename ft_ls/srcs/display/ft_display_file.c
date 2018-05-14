/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:31:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 19:11:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void			ft_display_file(t_file *file)
{
	int				type;

	type = ft_modetype(file->stat.st_mode);
	if (type == 1)	
		ft_putcolor_8("33", file->name);
	else if (type == 2)
		ft_putcolor_24("000;255;255", file->name);
	else if (type == 3)
		ft_putcolor_24("001;049;180", file->name);
	else if (type == 4)
		ft_putcolor_24("255;255;255", file->name);
	else if (type == 5)
		ft_putcolor_24("205;000;205", file->name);
	else if (type == 6)
		ft_putcolor_24("059;234;031", file->name);
	else
		ft_putcolor_24("255;255;255", file->name);
}
