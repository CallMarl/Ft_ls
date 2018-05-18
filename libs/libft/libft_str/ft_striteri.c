/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:32:33 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/12 15:24:07 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_striteri(char *str, void (*f)(unsigned int val, char *s))
{
	int i;

	if (str && f)
	{
		i = 0;
		while (str[i] != '\0')
		{
			(*f)(i, &str[i]);
			i++;
		}
	}
}
