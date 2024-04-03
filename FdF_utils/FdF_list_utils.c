/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:52:07 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/03 14:58:00 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_map	*find_next_point(t_map *current)
{
	t_map	*next_p;

	if (current->next == NULL)
		return (NULL);
	next_p = current->next;
	if (next_p->save_y == current->save_y && next_p->save_x == current->save_x + 30)
		return (next_p);
	return (NULL);
}

t_map	*find_sub_point(t_map *current)
{
	t_map	*iter;

	iter = current->next;
	while (iter)
	{
		if (iter->save_x == current->save_x && iter->save_y == current->save_y + 30)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
