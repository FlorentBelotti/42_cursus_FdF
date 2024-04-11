/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:51:44 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/11 19:27:13 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	apply_isometric_projection(t_data *data)
{
	t_map	*current;

	current = data->map_data;
	while (current)
	{
		save_modified_value(current);
		rotate_around_z_axis(current);
		rotate_around_x_axis(current, data);
		current = current->next;
	}
	get_offset(data);
	add_offset(data);
}

void	save_modified_value(t_map *cur)
{
	cur->save_x = cur->pos_x;
	cur->save_y = cur->pos_y;
	cur->save_z = cur->pos_z;
}

void	rotate_around_z_axis(t_map *cur)
{
	double	rad;

	rad = 45 * M_PI / 180.0;
	cur->pos_x = cur->save_x * cos(rad) - cur->save_y * sin(rad);
	cur->pos_y = cur->save_x * sin(rad) + cur->save_y * cos(rad);
}

void	rotate_around_x_axis(t_map *cur, t_data *data)
{
	double	rad;

	rad = 0.615;
	cur->pos_y = cur->save_y * cos(rad) - (cur->pos_z * data->mvt->projection)
		* sin(rad);
	cur->pos_z = cur->save_y * sin(rad) + (cur->pos_z * data->mvt->projection)
		* cos(rad);
}
