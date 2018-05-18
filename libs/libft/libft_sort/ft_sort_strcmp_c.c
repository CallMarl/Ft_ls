/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strcmp_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:51:34 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/09 16:07:28 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_sort_strcmp_c(const void *v1, const void *v2)
{
	return (ft_strcmp((*(const char **)v1), (*(const char **)v2)));
}
