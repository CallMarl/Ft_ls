/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:48:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:20:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"

extern void			ft_option_usize(uintmax_t *val, char *size_spe)
{
	if (size_spe == 0)
		*val = (unsigned int)(*val);
	else if (ft_strcmp("j", size_spe) == 0)
		*val = (uintmax_t)(*val);
	else if (ft_strcmp("z", size_spe) == 0)
		*val = (size_t)(*val);
	else if (ft_strcmp("l", size_spe) == 0)
		*val = (unsigned long)(*val);
	else if (ft_strcmp("h", size_spe) == 0)
		*val = (unsigned short)(*val);
	else if (ft_strcmp("ll", size_spe) == 0)
		*val = (unsigned long long)(*val);
	else
		*val = (unsigned char)(*val);
}

extern void			ft_option_size(uintmax_t *val, char *size_spe)
{
	if (size_spe == 0)
		*val = (int)(*val);
	else if (ft_strcmp("j", size_spe) == 0)
		*val = (intmax_t)(*val);
	else if (ft_strcmp("z", size_spe) == 0)
		*val = (size_t)*val;
	else if (ft_strcmp("l", size_spe) == 0)
		*val = (long)(*val);
	else if (ft_strcmp("h", size_spe) == 0)
		*val = (short)(*val);
	else if (ft_strcmp("ll", size_spe) == 0)
		*val = (long long)(*val);
	else
		*val = (char)(*val);
}
