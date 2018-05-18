/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:58:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/25 16:35:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Prends la chaine passé en paramettre puis la retourne en une copie
** dynamique, cette fonction utilise malloc().
*/

char		*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup)
	{
		dup = ft_strcpy(dup, s);
		dup[len] = '\0';
		return (dup);
	}
	return (0);
}
