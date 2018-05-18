/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_month.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:14:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:52:02 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "libft_time.h"

extern void		ft_time_month(time_t *clock, t_tm *date, t_bool bisex)
{
	static int	month[12] = {
		T_JAN, 0, T_MAR, T_APR, T_MAY, T_JUN,
		T_JUL, T_AUG, T_SEP, T_OCT, T_NOV, T_DEC
	};
	int			i;
	time_t		sec;
	time_t		svg;

	i = 0;
	sec = 0;
	svg = 0;
	month[1] = (bisex == TRUE) ? T_FEB + T_DAY : T_FEB;
	if (*clock < 0)
		(*clock) = -(*clock);
	while (sec <= *clock)
	{
		svg = sec;
		sec += month[i++];
		if (i == 12)
			i = 0;
	}
	date->month = i;
	(*clock) -= svg;
}
