/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nbweight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:20:51 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:23:39 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compte le nombre de chiffre dans un nombre
*/

extern int
	ft_utils_nbweight(int nb)
{
	int					i;

	i = 1;
	while ((nb /= 10) > 0)
		i++;
	return (i);
}
