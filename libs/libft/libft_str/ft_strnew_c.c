/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:42:36 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/15 11:02:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew_c(size_t size, char c)
{
	char	*str;
	size_t	i;

	if (!(str = ft_strnew(size)))
		return (0);
	i = 0;
	while (size--)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}
