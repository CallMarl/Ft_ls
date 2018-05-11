/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:31:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/11 19:50:22 by pprikazs         ###   ########.fr       */
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
		ft_putendl(file->name);
	}
	(void)pl;
	(void)p1;
	(void)pa;
}

