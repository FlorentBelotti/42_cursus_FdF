/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx_key_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:35:43 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/31 21:14:14 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	switch_assignment(int key_code, t_mlx *mlx, t_data *data)
{
	if (key_code == KEY_ESC)
		exit_using_key_esc(mlx, data);
	return (0);
}

void	exit_using_key_esc(t_mlx *mlx, t_data *data)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free_map_struct(data->map_data);
	exit(0);
}
