/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_mvt_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:03:11 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/11 19:25:20 by fbelotti         ###   ########.fr       */
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
	data->mvt->projection = 5;
	data->mvt->add_x = 0;
	data->mvt->add_y = 0;
	data->mvt->scale = 10;
	data->mvt->zoom = 1;
}

void	apply_zoom_to_point(t_data *data, float zoom)
{
	t_map	*current;

	current = data->map_data;
	while (current)
	{
		current->pos_x = round(current->pos_x * zoom);
		current->pos_y = round(current->pos_y * zoom);
		current->pos_z = round(current->pos_z * zoom);
		current = current->next;
	}
}
