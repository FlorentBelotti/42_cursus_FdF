/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx_key_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:35:43 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

int switch_assignment(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		exit_fdf(data);
	if (key_code == KEY_W || key_code == KEY_S || key_code == KEY_A || key_code == KEY_D)
		apply_translation(key_code, data);
	if (key_code == KEY_PLUS || key_code == KEY_MINUS)
		apply_projection(key_code, data);
	if (key_code == KEY_Q || key_code == KEY_E)
		apply_zoom(key_code, data);
	return (0);
}

void apply_zoom(int key_code, t_data *data)
{
	if (key_code == KEY_Q)
		data->mvt->zoom *= 1.1;
	if (key_code == KEY_E)
		data->mvt->zoom /= 1.1;
	ft_mlx_clear_window(data);
	get_original_map_data(data);
	apply_zoom_to_point(data, data->mvt->zoom);
	apply_isometric_projection(data);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							data->img->img_ptr, 0, 0);
}

void apply_projection(int key_code, t_data *data)
{
	if (key_code == KEY_PLUS)
		data->mvt->projection += 1;
	if (key_code == KEY_MINUS)
		data->mvt->projection -= 1;
	ft_mlx_clear_window(data);
	get_original_map_data(data);
	apply_isometric_projection(data);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							data->img->img_ptr, 0, 0);
}

void apply_translation(int key_code, t_data *data)
{
	if (key_code == KEY_W)
		data->mvt->add_y -= 10;
	if (key_code == KEY_S)
		data->mvt->add_y += 10;
	if (key_code == KEY_A)
		data->mvt->add_x -= 10;
	if (key_code == KEY_D)
		data->mvt->add_x += 10;
	ft_mlx_clear_window(data);
	get_original_map_data(data);
	apply_isometric_projection(data);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							data->img->img_ptr, 0, 0);
}

int exit_fdf(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->img->img_ptr);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
	free(data->img);
	free(data->mvt);
	free_map_struct(data->map_data);
	exit(0);
}
