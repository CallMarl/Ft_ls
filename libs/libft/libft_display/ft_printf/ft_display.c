/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:40:10 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:09 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern void			ft_displaybuff(t_list *elem)
{
	if (elem)
		ft_putmemory((void *)elem->content, elem->size);
}

extern void			ft_display_skel(t_skel **skel)
{
	int				i;
	int				j;
	int				size;

	i = 0;
	while (i < FT_SKEL_SIZE)
	{
		j = 1;
		size = skel[i][0].val;
		ft_putstr("Skel degree : ");
		ft_putnbr(i);
		ft_putchar('\n');
		while (j < size)
		{
			ft_putstr(skel[i][j].spe);
			ft_putstr(" : ");
			ft_putnbr(skel[i][j].val);
			ft_putchar('\n');
			j++;
		}
		if (i < 3)
			ft_putchar('\n');
		i++;
	}
}
