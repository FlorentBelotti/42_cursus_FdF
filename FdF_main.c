/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:33:38 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/06 17:46:31 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.map_data = NULL;
	get_and_parse_the_line(av[1], &data);
	data.mlx = init_mlx(&data);
	apply_isometric_projection(&data);
	init_mlx_image(&data);
	draw_grid(&data);
	mlx_put_image_to_window(data.mlx->mlx_ptr, data.mlx->win_ptr,
		data.img->img_ptr, 0, 0);
	mlx_key_hook(data.mlx->win_ptr, switch_assignment, data.mlx);
	mlx_loop(data.mlx->mlx_ptr);
	free_all(&data);
}
