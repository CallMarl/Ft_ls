/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:33:44 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:59:37 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** Fonction de trie rapide avec le pivot qui est l'indice du milieux du
** tableau
*/

extern void			ft_qsort(void *base, size_t nel, size_t width, \
		int (*cmp)(const void *, const void *))
{
	size_t			i;
	size_t			piv;
	unsigned char	*tmp;

	tmp = (unsigned char *)base;
	if (nel <= 0)
		return ;
	i = width;
	piv = 0;
	ft_memswap(tmp, &tmp[(nel / 2) * width], width);
	while (i < (nel) * width)
	{
		if ((*cmp)((void *)&tmp[i], (void *)tmp) < 0)
		{
			piv += width;
			ft_memswap(&tmp[i], &tmp[piv], width);
		}
		i += width;
	}
	ft_memswap(tmp, &tmp[piv], width);
	if (piv != 0)
		ft_qsort(tmp, piv / width, width, cmp);
	ft_qsort((void *)&tmp[piv + width], nel - ((piv / width) + 1), width, cmp);
}
