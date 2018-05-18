/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:25:22 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:31:49 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_memdel_size(void *content, size_t size)
{
	char	*tmp;

	tmp = content;
	while (size--)
		*tmp++ = 0;
	ft_memdel((void **)&content);
}
