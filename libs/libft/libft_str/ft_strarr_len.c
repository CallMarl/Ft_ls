/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:55:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 09:58:42 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int		ft_strarr_len(char **arr)
{
	int			len;
	char		**tmp;

	len = 0;
	if (arr == 0)
		return (len);
	tmp = arr;
	while (tmp != 0)
		len += ft_strlen(*tmp++);
	return (len);
}
