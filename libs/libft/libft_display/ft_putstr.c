/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:17:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 11:57:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Imprime la chaine de caractere passé en parametre sur la sortie standard.
*/

void		ft_putstr(const char *str)
{
	int		len;
	if (str)
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
}
