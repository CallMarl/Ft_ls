/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:58:39 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:06 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"
#define FT_SPEPTR_SIZE 3

static t_ptr		*ft_inidisplay_ptr(void)
{
	static t_ptr	ptr[] = {
		{"s", &ft_s}, {"S", &ft_bigs}, {"p", &ft_p}
	};

	return (ptr);
}

static t_list		*(*ft_callptr_fct(char *skel_val,\
			t_ptr *ptr))(void *, t_skel **)
{
	int				i;
	int				call_size;

	i = 0;
	call_size = FT_SPEPTR_SIZE;
	while (i < call_size)
	{
		if (ft_strcmp(skel_val, ptr[i].type) == 0)
			return (ptr[i].pfct);
		i++;
	}
	return (0);
}

extern int			ft_args_ptr(va_list ap, t_skel **skel, char *skel_val,\
		t_list **result)
{
	t_ptr			*ptr;
	t_list			*(*pfct)(void *, t_skel **);

	ptr = ft_inidisplay_ptr();
	if ((pfct = ft_callptr_fct(skel_val, ptr)))
	{
		*result = pfct(va_arg(ap, void *), skel);
		return (1);
	}
	return (0);
}
