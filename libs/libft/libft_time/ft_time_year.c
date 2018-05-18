/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_year.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:15:38 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/16 12:33:04 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "libft_time.h"

extern void		ft_time_year(time_t *clock, t_tm *date)
{
	short			year;
	time_t			sec;
	time_t			svg;
	int				sig;

	year = (short)BASE_YEAR - 1;
	sec = 0;
	svg = 0;
	sig = 1;
	if (*clock < 0)
	{
		sec = *clock;
		*clock = 0;
		sig = -1;
	}
	while (sec <= *clock)
	{
		svg = sec;
		sec += (ft_isbisextil(year) == FALSE) ? T_YEAR : T_YEAR + T_DAY;
		year += sig;
	}
	date->year = year;
	(*clock) -= svg;
}
