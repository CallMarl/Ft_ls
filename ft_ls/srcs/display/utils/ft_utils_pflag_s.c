/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pflag_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:35:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 19:04:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** insert un %s avec une valeur dispval dans str. Par exemple %10s.
*/

extern size_t		ft_utils_pflag_s(char **str, int dispval, \
		size_t count)
{
	char			*tmp;

	count += ft_strcpy_x(&(*str)[count], "%");
	tmp = ft_utils_insertnbr(&(*str)[count], dispval);
	count += ((size_t)tmp - (size_t)&(*str)[count]);
	count += ft_strcpy_x(&(*str)[count], "s");
	return (count);
}
