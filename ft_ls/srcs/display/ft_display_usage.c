/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:30:34 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:12:54 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern void
	ft_display_usage(void)
{
	ft_putstr("ls : illegal option\nusage : ls [-RTahlnrst1] [file ...]\n");
}
