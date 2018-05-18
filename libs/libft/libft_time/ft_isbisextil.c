/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbisextil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:07:52 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:53:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft_time.h"

extern t_bool		ft_isbisextil(short date)
{
	t_bool			bisex;

	bisex = FALSE;
	if (date % 4 == 0 || date % 100 == 0)
		bisex = TRUE;
	if (date % 400 == 0)
		bisex = FALSE;
	return (bisex);
}
