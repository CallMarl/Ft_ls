/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:14:34 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:59:43 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		ft_memextend(void **m1, const void *m2, \
		size_t m1_size, size_t m2_size)
{
	void		*cpy;

	if (*m1 == 0)
	{
		if (!(*m1 = ft_memalloc(sizeof(char) * m2_size)))
			return (-1);
		*m1 = ft_memcpy(*m1, m2, m2_size);
		return (m2_size);
	}
	if (!(cpy = ft_memalloc(sizeof(char) * m1_size)))
		return (0);
	cpy = ft_memcpy(cpy, *m1, sizeof(char) * m1_size);
	ft_memdel((void **)m1);
	*m1 = ft_memjoin(cpy, m2, m1_size, m2_size);
	ft_memdel((void **)&cpy);
	return (m1_size + m2_size);
}

static int		read_buff(char *tmp, t_buff *f, char **str)
{
	int			i;
	char		*b_tmp;

	i = f->cr;
	b_tmp = (char *)(f->buff);
	while (f->cr < f->b_size && b_tmp[f->cr] != '\n' && b_tmp[f->cr] != -1)
	{
		ft_memcpy((void *)&tmp[f->cr - i], (void *)&(b_tmp[f->cr]), \
				sizeof(char));
		(f->cr)++;
	}
	if (f->cr < f->b_size && (b_tmp[f->cr] == '\n' || b_tmp[f->cr] == -1))
		(f->cr)++;
	if (!(f->e_size = ft_memextend((void **)str, (void *)tmp, \
					f->e_size, f->cr - i)))
		return (-1);
	else if (b_tmp[f->cr - 1] == '\n' || (b_tmp[f->cr - 1] == -1 \
			&& f->e_size > 0 && f->cr < f->b_size))
		return (f->e_size);
	return (0);
}

static int		ini_buff(int fd, void **buff, size_t *cr, size_t *b_size)
{
	int ret;

	ret = 1;
	if (*buff != NULL)
		ft_memdel((void **)buff);
	if (!(*buff = ft_memalloc(sizeof(char) * FT_BUFF_SIZE)))
		ret = -1;
	if (ret == 1)
	{
		ret = read(fd, *buff, FT_BUFF_SIZE);
		*b_size = (ret != FT_BUFF_SIZE) ? ret + 1 : ret;
		if (ret == 0)
			ft_memdel((void **)buff);
		*cr = 0;
	}
	return (ret);
}

static int		return_value(int fd, char **line, t_buff *f, char *str)
{
	int				ret;
	char			tmp[FT_BUFF_SIZE];

	while (1)
	{
		if (f->cr >= f->b_size || f->buff == 0)
		{
			if ((ret = ini_buff(fd, &(f->buff), &(f->cr), &(f->b_size))) == 0)
				break ;
			else if (ret == -1)
				return (-1);
		}
		if ((ret = read_buff(tmp, f, &str)) >= 1)
			break ;
		else if (ret == -1)
			return (-1);
	}
	if (ret == 0 && tmp[0] != 0 && f->b_size == 1)
	{
		tmp[0] = 0;
		ret = f->e_size;
	}
	ret = f->e_size;
	*line = str;
	return (ret);
}

extern int		ft_gnl(int fd, char **line)
{
	static t_buff	file[FT_MAX_FD];
	char			*str;

	str = NULL;
	file[fd].e_size = 0;
	if (!line || fd < 0 || FT_MAX_FD <= fd)
		return (-1);
	return (return_value(fd, line, &file[fd], str));
}
