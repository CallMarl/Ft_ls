/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstset_heap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:20:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/23 19:36:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_rlstset_heap(t_rot *rot)
{
	t_dlist		*heap;

	heap = 0;
	if (rot->head != 0)
	{
		heap = rot->head;
		if (heap->prev != 0)
		{
			heap->prev->next = 0;
			heap->prev = 0;
		}
		rot->head = 0;
		rot->size = 0;
	}
	return (heap);
}
