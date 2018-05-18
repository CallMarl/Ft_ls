/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strimplode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:44:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:57:32 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_implode_len(char **arr, char *occ)
{
	int			len;

	if (occ == 0 || arr == 0)
		return (0);
	len = ft_strarr_len(arr);
	len += ft_strlen(occ) * ft_strarr_size(arr);
	return (len);
}

extern char		*ft_strimplode(char **arr, char *occ)
{
	int			len;
	char		*imp;
	char		**tmp;
	int			i;

	len = ft_implode_len(arr, occ);
	if (!(imp = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	tmp = arr;
	while (i <= len)
	{
		i += ft_strlcpy(&imp[i], *tmp++);
		i += ft_strlcpy(&imp[i], occ);
	}
	return (imp);
}
