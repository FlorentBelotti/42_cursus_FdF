/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:46:13 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/01 22:37:22 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 2000 || y < 0 || y > 2000)
		return ;
	dst = img->img_addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_gradient(int p1, int p2, int grad)
{
	t_map	col_1;
	t_map	col_2;
	int		comp;

	if (p1 == p2 || grad == 0)
		return (p1);
	comp = p1;
	col_1.pos_x = p1 % 256;
	p1 /= 256;
	col_1.pos_y = p1 % 256;
	p1 /= 256;
	col_1.pos_z = p1 % 256;
	col_2.pos_x = p2 % 256;
	p2 /= 256;
	col_2.pos_y = p2 % 256;
	p2 /= 256;
	col_2.pos_z = p2 % 256;
	return (get_nuance(comp, col_1, col_2, grad));
}

int	get_nuance(int comp, t_map col_1, t_map col_2, int grad)
{
	int	temp;

	if (col_1.pos_x > col_2.pos_x)
		comp -= grad * abs(col_2.pos_x - col_1.pos_x) / 100;
	if (col_1.pos_x < col_2.pos_x)
		comp += grad * abs(col_2.pos_x - col_1.pos_x) / 100;
	if (col_1.pos_x > col_2.pos_y)
		temp = grad * abs(col_2.pos_y - col_1.pos_y) / 100;
	if (col_1.pos_y > col_2.pos_y)
		comp -= 256 * temp;
	if (col_1.pos_y < col_2.pos_y)
		temp = grad * abs(col_2.pos_y - col_1.pos_y) / 100;
	if (col_1.pos_y < col_2.pos_y)
		comp += 256 * temp;
	if (col_1.pos_z > col_2.pos_z)
	{
		temp = grad * abs(col_2.pos_z - col_1.pos_z) / 100;
		comp -= 256 * 256 * temp;
	}
	if (col_1.pos_z < col_2.pos_z)
	{
		temp = comp * abs(col_2.pos_z - col_1.pos_z) / 100;
		comp += 256 * 256 * temp;
	}
	return (comp);
}
