/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pflag_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:38:17 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:12:00 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** insert un %d avec une valeur dispval dans str. Par exemple %10d.
*/

extern size_t
	ft_utils_pflag_d(char **str, int dispval, size_t count)
{
	char		*tmp;

	count += ft_strcpy_x(&(*str)[count], "%");
	tmp = ft_utils_insertnbr(&(*str)[count], dispval);
	count += ((size_t)tmp - (size_t)&(*str)[count]);
	count += ft_strcpy_x(&(*str)[count], "d");
	return (count);
}
