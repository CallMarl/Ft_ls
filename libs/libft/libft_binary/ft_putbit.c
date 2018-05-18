/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:26:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:23:25 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** C'est fonction imprime la data en binaire
*/

void		ft_putbit(void *data, size_t n)
{
	char		*tmp;
	char		str[MEM_SIZE * 8 + 1];
	char		*bits;

	tmp = data;
	if ((bits = ft_strnew(MEM_SIZE * 8 * n + 1)))
	{
		while (n--)
			ft_strcat(bits, ft_base2(*(tmp + n), str));
		ft_putstr(bits);
	}
}
