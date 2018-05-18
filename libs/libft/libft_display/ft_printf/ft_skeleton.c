/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skeleton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:47:58 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:18:26 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_skel		**ft_addempty_skel(void)
{
	static t_skel	display_spe[] = {
		{"size", 17}, {"s", 1}, {"S", 1}, {"p", 1}, {"d", 1}, {"D", 1},
		{"i", 1}, {"o", 1}, {"O", 1}, {"u", 1}, {"U", 1}, {"x", 1},
		{"X", 1}, {"c", 1}, {"C", 1}, {"%", 1}, {"undef", 1}
	};
	static t_skel	size_spe[] = {
		{"size", 7}, {"j", 1}, {"z", 1}, {"l", 1}, {"h", 1}, {"ll", 1},
		{"hh", 0}
	};
	static t_skel	accuracy_spe[] = {
		{"size", 3}, {"1", 1}, {"2", 1}
	};
	static t_skel	disposition_spe[] = {
		{"size", 6}, {"+", 1}, {" ", 1}, {"-", 1}, {"0", 1}, {"#", 1}
	};
	static t_skel	*skel[FT_SKEL_SIZE] = {
		display_spe, size_spe, accuracy_spe, disposition_spe
	};

	return (skel);
}

extern t_skel		**ft_initialize_skel(char *flag, int size)
{
	t_skel		**skel;

	skel = ft_addempty_skel();
	skel = ft_reset_skel(skel);
	skel = ft_analyze_flag(flag, size - 1, skel);
	return (skel);
}
