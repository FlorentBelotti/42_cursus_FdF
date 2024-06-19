/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:33:38 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:02 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/FdF.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_printf("ERROR : ./FdF ./file_name");
		return (0);
	}
	data.map_data = NULL;
	init_mvt(&data);
	get_and_parse_the_line(av[1], &data);
	data.mlx = init_mlx(&data);
	apply_zoom_to_point(&data, data.mvt->zoom);
	apply_isometric_projection(&data);
	init_mlx_image(&data);
	draw_grid(&data);
	mlx_put_image_to_window(data.mlx->mlx_ptr, data.mlx->win_ptr,
							data.img->img_ptr, 0, 0);
	mlx_key_hook(data.mlx->win_ptr, switch_assignment, &data);
	mlx_hook(data.mlx->win_ptr, 17, 0, exit_fdf, &data);
	mlx_loop(data.mlx->mlx_ptr);
}
