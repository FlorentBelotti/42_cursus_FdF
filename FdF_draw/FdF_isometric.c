/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:40:35 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/03 17:06:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	init_mvt(t_data *data)
{
	data->mvt = malloc(sizeof(t_mvt));
	if (!data->mvt)
		return ;
	data->mvt->angle = M_PI / 4;
	data->mvt->v_zoom = 10;
	data->mvt->grid_width = data->col_nb * data->mvt->v_zoom;
	data->mvt->grid_height = data->line_nb * data->mvt->v_zoom;
	data->mvt->max_x = INT_MIN;
	data->mvt->min_x = INT_MAX;
	data->mvt->max_y = INT_MIN;
	data->mvt->min_y = INT_MAX;
}

void	get_offset(t_data *data)
{
	t_map	*cur;
	int		temp_x;
	int		temp_y;

	cur = data->map_data;
	while (cur)
	{
		temp_x = (cur->pos_x - cur->pos_y) * cos(data->mvt->angle)
			+ data->mvt->v_zoom;
		temp_y = ((cur->pos_x + cur->pos_y) * sin(data->mvt->angle)
				- cur->pos_z) - data->mvt->v_zoom;
		if (temp_x > data->mvt->max_x)
			data->mvt->max_x = temp_x;
		if (temp_x < data->mvt->min_x)
			data->mvt->min_x = temp_x;
		if (temp_y > data->mvt->max_y)
			data->mvt->max_y = temp_y;
		if (temp_y < data->mvt->min_y)
			data->mvt->min_y = temp_y;
		cur = cur->next;
	}
	data->mvt->offset_x = (WIN_WIDTH - (data->mvt->max_x - data->mvt->min_x))
		/ 2 - data->mvt->min_x;
	data->mvt->offset_y = (WIN_HEIGHT - (data->mvt->max_y - data->mvt->min_y))
		/ 2 - data->mvt->min_y;
}

void	iso_projection(t_data *data)
{
	t_map	*cur;

	init_mvt(data);
	get_offset(data);
	cur = data->map_data;
	while (cur)
	{
		cur->save_x = cur->pos_x;
		cur->save_y = cur->pos_y;
		cur->pos_x = (cur->save_x - cur->save_y) * cos(data->mvt->angle)
			+ data->mvt->v_zoom + data->mvt->offset_x;
		cur->pos_y = ((cur->save_x + cur->save_y) * sin(data->mvt->angle)
				- cur->pos_z) + data->mvt->v_zoom + data->mvt->offset_y;
		cur = cur->next;
	}
}
