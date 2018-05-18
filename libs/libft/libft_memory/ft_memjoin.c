/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:48:56 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/05/01 18:56:35 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(const void *s1, const void *s2, size_t l1, size_t l2)
{
	void *dst;

	if (!s1 && !s2)
		return (0);
	if (!(dst = ft_memalloc(l1 + l2)))
		return (0);
	ft_memcpy(dst, s1, l1);
	ft_memcpy(dst + l1, s2, l2);
	return (dst);
}
