/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:38:57 by pprikazs          #+#    #+#             */
/*   Updated: 2018/01/29 17:34:37 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int val, char c))
{
	char	*mstr;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((mstr = (char *)(malloc(sizeof(char) * (len + 1)))) == NULL)
		return (NULL);
	else
	{
		i = 0;
		mstr[len] = '\0';
		while (s[i] != '\0')
		{
			mstr[i] = (*f)(i, s[i]);
			i++;
		}
		return (mstr);
	}
}
