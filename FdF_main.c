/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:33:38 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/09 16:50:16 by fbelotti         ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.map_data = NULL;
	get_and_parse_the_line(av[1], &data);
	data.mlx = init_mlx(&data);
	init_mvt(&data);
	apply_isometric_projection(&data);
	init_mlx_image(&data);
	draw_grid(&data);
	mlx_put_image_to_window(data.mlx->mlx_ptr, data.mlx->win_ptr,
		data.img->img_ptr, 0, 0);
	mlx_key_hook(data.mlx->win_ptr, switch_assignment, &data);
	mlx_loop(data.mlx->mlx_ptr);
}
