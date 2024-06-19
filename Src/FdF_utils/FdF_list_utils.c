/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:52:07 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

t_map *find_next_point(t_map *current)
{
	t_map *next_p;

	if (current->next == NULL)
		return (NULL);
	next_p = current->next;
	if (next_p->save_y == current->save_y)
		return (next_p);
	return (NULL);
}

t_map *find_sub_point(t_map *current)
{
	t_map *iter;

	if (current->next == NULL)
		return (NULL);
	iter = current->next;
	while (iter)
	{
		if (iter->save_x == current->save_x && iter->save_y != current->save_y)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
