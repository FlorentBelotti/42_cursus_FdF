/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx_key_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:35:43 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/09 16:50:57 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	switch_assignment(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		exit_using_key_esc(data);
	if (key_code == KEY_W || key_code == KEY_S || key_code == KEY_A
		|| key_code == KEY_D)
		translate_offset(key_code, data);
	if (key_code == KEY_Q || key_code == KEY_E)
		apply_zoom_effect(key_code, data);
	return (0);
}

void	apply_zoom_effect(int key_code, t_data *data)
{
	if (key_code == KEY_E)
		data->mvt->projection += 1;
	if (key_code == KEY_Q)
		data->mvt->projection -= 1;
	ft_mlx_clear_window(data);
	get_original_map_data(data);
	apply_isometric_projection(data);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->img->img_ptr, 0, 0);
}

void	translate_offset(int key_code, t_data *data)
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

void	exit_using_key_esc(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->img->img_ptr);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx->win_ptr);
	free_map_struct(data->map_data);
	exit(0);
}
