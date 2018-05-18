/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_localtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:10:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:53:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft_time.h"

extern void		ft_time_day(time_t *clock, t_tm *date)
{
	int			i;
	time_t		sec;
	time_t		svg;

	i = 0;
	sec = 0;
	svg = 0;
	if (*clock < 0)
		(*clock) = -(*clock);
	while (sec <= *clock)
	{
		svg = sec;
		sec += T_DAY;
		i++;
	}
	date->day = i - 1;
	(*clock) -= svg;
}

extern void		ft_time_hour(time_t *clock, t_tm *date)
{
	int			i;
	time_t		sec;
	time_t		svg;

	i = 0;
	sec = 0;
	svg = 0;
	if (*clock < 0)
		(*clock) = -(*clock);
	while (sec <= *clock)
	{
		svg = sec;
		sec += T_HOUR;
		i++;
	}
	date->hour = i - 1;
	(*clock) -= svg;
}

extern void		ft_time_min(time_t *clock, t_tm *date)
{
	int			i;
	time_t		sec;
	time_t		svg;

	i = 0;
	sec = 0;
	svg = 0;
	if (*clock < 0)
		(*clock) = -(*clock);
	while (sec <= *clock)
	{
		svg = sec;
		sec += T_MIN;
		i++;
	}
	date->min = i - 1;
	(*clock) -= svg;
}

extern t_tm		*ft_localtime(time_t *clock)
{
	t_tm			*date;
	time_t			tmp;

	tmp = *clock;
	tmp += T_UTC * T_HOUR;
	if (!(date = (t_tm *)ft_memalloc(sizeof(t_tm))))
		return (0);
	date->nbd = tmp / T_DAY;
	ft_time_year(&tmp, date);
	ft_time_month(&tmp, date, ft_isbisextil(date->year));
	ft_time_day(&tmp, date);
	ft_time_hour(&tmp, date);
	ft_time_min(&tmp, date);
	date->sec = tmp;
	return (date);
}
