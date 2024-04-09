/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:59:41 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/09 16:50:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	add_offset(t_data *data)
{
	t_map	*cur;
	t_mvt	*mvt;

	mvt = data->mvt;
	cur = data->map_data;
	while (cur)
	{
		cur->pos_x += mvt->offset_x;
		cur->pos_y += mvt->offset_y;
		cur = cur->next;
	}
}

void	get_offset(t_data *data)
{
	t_map	*cur;
	t_mvt	*mvt;

	mvt = data->mvt;
	cur = data->map_data;
	while (cur)
	{
		if (cur->pos_x > mvt->max_x)
			mvt->max_x = cur->pos_x;
		if (cur->pos_x < mvt->min_x)
			mvt->min_x = cur->pos_x;
		if (cur->pos_y > mvt->max_y)
			mvt->max_y = cur->pos_y;
		if (cur->pos_y < mvt->min_y)
			mvt->min_y = cur->pos_y;
		cur = cur->next;
	}
	mvt->offset_x = ((WIN_WIDTH - (mvt->max_x - mvt->min_x)) / 2 - mvt->min_x)
		+ mvt->add_x;
	mvt->offset_y = ((WIN_HEIGHT - (mvt->max_y - mvt->min_y)) / 2 - mvt->min_y)
		+ mvt->add_y;
}
