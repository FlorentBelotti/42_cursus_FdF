/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:31:55 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/21 15:29:16 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	initialize_mlx(t_data *data)
{
	t_mlx	*mlx;

	data->mlx = malloc(sizeof(t_mlx));
	mlx = data->mlx;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		write (2, "ERROR : MLX can't initialize\n", 29);
		free(mlx);
		return ;
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!mlx->win_ptr)
	{
		write (2, "ERROR : MLX window can't open\n", 30);
		free(mlx->mlx_ptr);
		free(mlx);
		return ;
	}
	mlx_key_hook(mlx->win_ptr, switch_assignment, mlx);
	mlx_loop(mlx->mlx_ptr);
}
