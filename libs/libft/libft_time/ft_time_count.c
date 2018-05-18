/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:13:39 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/16 15:20:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft_time.h"

extern int		ft_time_count(time_t *clock, int time_type)
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
		sec += time_type;
		i++;
	}
	if (i == 0)
		return (1);
	(*clock) -= svg;
	return (i);
}
