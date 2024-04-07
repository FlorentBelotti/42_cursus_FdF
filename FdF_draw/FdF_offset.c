/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:59:41 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/07 14:47:08 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	init_mvt(t_data *data)
{
	data->mvt = malloc(sizeof(t_mvt));
	if (!data->mvt)
		return ;
	data->mvt->max_x = INT_MIN;
	data->mvt->min_x = INT_MAX;
	data->mvt->max_y = INT_MIN;
	data->mvt->min_y = INT_MAX;
	data->mvt->scale_factor = 5;
}

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
	mvt->offset_x = (WIN_WIDTH - (mvt->max_x - mvt->min_x)) / 2 - mvt->min_x;
	mvt->offset_y = (WIN_HEIGHT - (mvt->max_y - mvt->min_y)) / 2 - mvt->min_y;
}
