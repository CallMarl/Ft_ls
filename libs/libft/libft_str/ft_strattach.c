/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strattach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:21:48 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/10 10:48:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** Relie 2 chaines de caracteres joint par un élément au milieux
*/

extern char		*ft_strattach(const char *str1, const char *str2, \
		const char *occ)
{
	char		*dest;
	size_t		len;
	size_t		i;

	if (str1 == 0 || str2 == 0)
		return (0);
	len = ft_strlen(str1);
	len += ft_strlen(str2);
	if (occ != 0)
		len += ft_strlen(occ);
	if (!(dest = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
	i = ft_strlcpy(dest, str1);
	i += ft_strlcpy(&dest[i], occ);
	i += ft_strlcpy(&dest[i], str2);
	return (dest);
}
