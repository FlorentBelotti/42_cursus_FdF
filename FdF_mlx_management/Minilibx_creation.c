/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:31:55 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/02 13:40:04 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_mlx	*init_mlx(t_data *data)
{
	t_mlx	*mlx;

	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		return (NULL);
	mlx = data->mlx;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		free(mlx);
		return (NULL);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!mlx->win_ptr)
	{
		free(mlx->mlx_ptr);
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

void	init_mlx_image(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		return ;
	data->img->img_ptr = mlx_new_image(data->mlx->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!data->img->img_ptr)
	{
		free(data->img);
		return ;
	}
	data->img->img_addr = mlx_get_data_addr(data->img->img_ptr,
			&(data)->img->bits_per_pixel, &(data)->img->line_len,
			&(data)->img->endian);
}

void	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->img->img_ptr, 0, 0);
}
