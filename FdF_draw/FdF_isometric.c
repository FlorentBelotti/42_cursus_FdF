/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:51:44 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/05 16:01:08 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	apply_isometric_projection(t_data *data)
{
	t_map	*current;

	current = data->map_data;
	init_mvt(data);
	while (current)
	{
		save_value(current, data);
		rotate_around_z_axis(current);
		rotate_around_x_axis(current);
		current = current->next;
	}
	get_offset(data);
	add_offset(data);
}

void	save_value(t_map *cur, t_data *data)
{
	cur->save_x = cur->pos_x;
	cur->save_y = cur->pos_y;
	cur->save_z = cur->pos_z * data->mvt->scale_factor;
}

void	rotate_around_z_axis(t_map *cur)
{
	double	rad;

	rad = 45 * M_PI / 180.0;
	cur->pos_x = cur->save_x * cos(rad) - cur->save_y * sin(rad);
	cur->pos_y = cur->save_x * sin(rad) + cur->save_y * cos(rad);
}

void	rotate_around_x_axis(t_map *cur)
{
	double	rad;

	rad = 0.615;
	cur->pos_y = cur->save_y * cos(rad) - cur->save_z * sin(rad);
	cur->pos_z = cur->save_y * sin(rad) + cur->save_z * cos(rad);
}
