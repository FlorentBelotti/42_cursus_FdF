/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:55:23 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/07 17:01:06 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	draw_horizontal(t_point *p_data, t_map *p1, t_map *p2, t_data *data)
{
	int	dec;
	int	x;
	int	y;
	int	grad;
	int	div;

	x = p1->pos_x;
	y = p1->pos_y;
	grad = 0;
	div = sqrt(pow(p1->pos_x - p2->pos_x, 2) + pow(p1->pos_y - p2->pos_y, 2));
	dec = 2 * p_data->diff_y - p_data->diff_x;
	while (x != p2->pos_x)
	{
		ft_mlx_pixel_put(data->img, x, y, get_gradient(p1->color_code,
				p2->color_code, grad));
		if (dec > 0)
		{
			y += p_data->step_y;
			dec -= 2 * p_data->diff_x;
		}
		x += p_data->step_x;
		dec += 2 * p_data->diff_y;
		grad = (sqrt(pow(p1->pos_x - p1->pos_x, 2)
					+ pow(p1->pos_y - p1->pos_y, 2)) / div) * 100;
	}
}

void	draw_vertical(t_point *p_data, t_map *p1, t_map *p2, t_data *data)
{
	int	dec;
	int	x;
	int	y;
	int	grad;
	int	div;

	x = p1->pos_x;
	y = p1->pos_y;
	grad = 0;
	div = sqrt(pow(p1->pos_x - p2->pos_x, 2) + pow(p1->pos_y - p2->pos_y, 2));
	dec = 2 * p_data->diff_x - p_data->diff_y;
	while (y != p2->pos_y)
	{
		ft_mlx_pixel_put(data->img, x, y, get_gradient(p1->color_code,
				p2->color_code, grad));
		if (dec > 0)
		{
			x += p_data->step_x;
			dec -= 2 * p_data->diff_y;
		}
		y += p_data->step_y;
		dec += 2 * p_data->diff_x;
		grad = (sqrt(pow(p1->pos_x - p1->pos_x, 2)
					+ pow(p1->pos_y - p1->pos_y, 2)) / div) * 100;
	}
}

void	choose_draw(t_map *p1, t_map *p2, t_data *data)
{
	t_point	*p_data;

	p_data = init_bresenham(p1, p2);
	if (comp_abs_val(p_data) == 1)
		draw_horizontal(p_data, p1, p2, data);
	else if (comp_abs_val(p_data) == 0)
		draw_vertical(p_data, p1, p2, data);
}

t_point	*init_bresenham(t_map *p1, t_map *p2)
{
	t_point	*p_data;

	p_data = malloc(sizeof(t_point));
	if (!p_data)
		return (NULL);
	p_data->diff_x = abs(p2->pos_x - p1->pos_x);
	p_data->diff_y = abs(p2->pos_y - p1->pos_y);
	if (p1->pos_x < p2->pos_x)
		p_data->step_x = 1;
	else
		p_data->step_x = -1;
	if (p1->pos_y < p2->pos_y)
		p_data->step_y = 1;
	else
		p_data->step_y = -1;
	return (p_data);
}

void	draw_grid(t_data *data)
{
	t_map	*current;
	t_map	*next_p;
	t_map	*sub_p;

	current = data->map_data;
	while (current != NULL)
	{
		next_p = find_next_point(current);
		if (next_p != NULL)
			choose_draw(current, next_p, data);
		sub_p = find_sub_point(current);
		if (sub_p != NULL)
			choose_draw(current, sub_p, data);
		current = current->next;
	}
}
