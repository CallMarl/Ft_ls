/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:15:14 by tdeborde          #+#    #+#             */
/*   Updated: 2018/01/29 17:31:15 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_next_sqrt(int nb)
{
	int div;

	div = ft_sqrt(nb);
	if (div)
		return (div);
	else
		return (ft_next_sqrt(nb + 1));
}
