/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:52:07 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/01 11:52:26 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_map	*find_next_point(t_map *current)
{
	t_map	*next_p;

	if (current->next == NULL)
		return (NULL);
	next_p = current->next;
	if (next_p->pos_y == current->pos_y && next_p->pos_x == current->pos_x + 30)
		return (next_p);
	return (NULL);
}

t_map	*find_sub_point(t_map *current)
{
	t_map	*iter;

	iter = current->next;
	while (iter)
	{
		if (iter->pos_x == current->pos_x && iter->pos_y == current->pos_y + 30)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
