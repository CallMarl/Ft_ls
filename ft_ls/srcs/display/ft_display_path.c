/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:36:09 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 11:58:32 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"

extern void			ft_display_path1(char *path)
{
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
}

extern void			ft_display_path2(char *path)
{
	ft_putstr(path);
	ft_putstr(":\n");
}
