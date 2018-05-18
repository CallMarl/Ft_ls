/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:17:14 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/16 12:28:45 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TIME_H
# define LIBFT_TIME_H

# include <sys/time.h>
# include "libft.h"

# define BASE_YEAR 1970

# define T_MIN 60
# define T_HOUR 3600
# define T_DAY 86400
# define T_JAN 2678400
# define T_FEB 2419200
# define T_MAR 2678400
# define T_APR 2592000
# define T_MAY 2678400
# define T_JUN 2592000
# define T_JUL 2678400
# define T_AUG 2678400
# define T_SEP 2592000
# define T_OCT 2678400
# define T_NOV 2592000
# define T_DEC 2678400
# define T_YEAR 31536000

t_bool			ft_isbisextil(short date);
void			ft_time_day(time_t *clock, t_tm *date);
void			ft_time_hour(time_t *clock, t_tm *date);
void			ft_time_min(time_t *clock, t_tm *date);
void			ft_time_month(time_t *clock, t_tm *date, t_bool bisex);
void			ft_time_year(time_t *clock, t_tm *date);

#endif
