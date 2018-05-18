/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_localtime_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:12:22 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/16 15:38:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft_time.h"

extern t_tm			*ft_localtime_r(time_t *clock, t_tm *date)
{
	time_t			tmp;

	tmp = *clock;
	tmp += T_UTC * T_HOUR;
	date->nbd = tmp / T_DAY;
	ft_time_year(&tmp, date);
	ft_time_month(&tmp, date, ft_isbisextil(date->year));
	ft_time_day(&tmp, date);
	ft_time_hour(&tmp, date);
	ft_time_min(&tmp, date);
	date->sec = tmp;
	return (date);
}
