/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_openstat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:43:32 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/15 15:48:24 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "libft.h"

extern int			ft_err_openstat(void)
{
	char			*str;

	str = "ls";
	perror(str);
	ft_putendl(str);
	return (-1);
}
