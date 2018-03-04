/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:14:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/04 17:29:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool			ft_param_get(t_param **params, char key)
{
	int			i;

	i = 0;
	while (params[i]->key != 0)
	{
		if (params[i]->key == key)
			return (params[i]->val);
		i++;
	}
	return (FALSE);
}
