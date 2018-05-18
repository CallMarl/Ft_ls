/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:10:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:24:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** affiche une chaine de caractere unicode.
*/

void			ft_putstr_u(char *str)
{
	while (*str)
		str += ft_putchar_u(str) + 1;
}
