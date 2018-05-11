/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:26:00 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/11 18:38:39 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Variable global définissant les différente paramettre appelé par la commande
** ft_ls. Si le flag est à un alors il est définit sinon non.
*/

t_param		g_param[] = 
{
	{'l', 0},
	{'1', 0},
	{'R', 0},
	{'a', 0},
	{'r', 0},
	{'t', 0},
	{0, 0}
};
