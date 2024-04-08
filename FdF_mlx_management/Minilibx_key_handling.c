/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx_key_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:35:43 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/08 15:23:22 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	switch_assignment(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		exit_using_key_esc(data);
	return (0);
}

void	exit_using_key_esc(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->img->img_ptr);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx->win_ptr);
	//free(data->mvt);
	//free(data->p_data);
	free_map_struct(data->map_data);
	exit(0);
}
