/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:35:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/08 19:36:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

extern void			ft_memswap(void *s1, void *s2, size_t width)
{
	char			tmp;
	char			*tmp1;
	char			*tmp2;
	size_t			i;

	i = 0;
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (i < width)
	{
		tmp = tmp2[i];
		tmp2[i] = tmp1[i];
		tmp1[i] = tmp;
		i++;
	}
}
