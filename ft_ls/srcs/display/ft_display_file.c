/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:31:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/13 19:07:26 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

extern void			ft_display_file(t_file *file, int pl, int p1, int pa)
{
	if (file->err != 0)
		;// display error
	else
	{
		if (pl != 0 && pl > p1)
		{
			if (pa != 0)
			{
				//ft_displaydetail(file);
				ft_putendl(file->name);
			}
			else if (file->name[0] != '.')
			{
				//ft_displaydetail(file);
				ft_putendl(file->name);
			}
		}
		else if (p1 != 0 && p1 > 0)
		{
			if (pa != 0)
				ft_putendl(file->name);
			else if (file->name[0] != '.')
				ft_putendl(file->name);
		}
	}
}

