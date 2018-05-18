/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:49:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 09:56:25 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int			ft_strarr_size(char **arr)
{
	int		size;
	char	**tmp;

	size = 0;
	if (arr == 0)
		return (size);
	tmp = arr;
	while (tmp != 0)
	{
		size++;
		tmp++;
	}
	return (size);
}
