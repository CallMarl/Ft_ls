/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:23:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/14 19:20:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;

	if (size > 4294967295)
		return (NULL);
	if ((tmp = (void *)malloc(size)) == NULL)
		return (NULL);
	return (ft_bzero(tmp, size));
}
