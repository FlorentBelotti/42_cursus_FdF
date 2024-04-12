/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:46:13 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/09 14:53:47 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	dst = img->img_addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calculate_color_gradient(int p1, int p2, int perc)
{
	int	color1;
	int	color2;
	int	new_color;

	if (p1 == p2 || perc == 0)
		return (p1);
	color1 = (p1 >> 16) & 0xFF;
	color2 = (p2 >> 16) & 0xFF;
	new_color = ((color1 + ((color2 - color1) * perc / 100)) & 0xFF) << 16;
	color1 = (p1 >> 8) & 0xFF;
	color2 = (p2 >> 8) & 0xFF;
	new_color |= ((color1 + ((color2 - color1) * perc / 100)) & 0xFF) << 8;
	color1 = p1 & 0xFF;
	color2 = p2 & 0xFF;
	new_color |= (color1 + ((color2 - color1) * perc / 100)) & 0xFF;
	return (new_color);
}
