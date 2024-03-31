/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_Bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:55:23 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/31 17:33:22 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	draw_horizontal(t_point *p_data, t_map *p1, t_map *p2, t_data *data)
{
	int	dec;
	int	x;
	int	y;

	x = p1->pos_x;
	y = p1->pos_y;
	dec = 2 * p_data->diff_y - p_data->diff_x;
	while (x < p2->pos_x)
	{
		mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->win_ptr, x, y, p1->color_code);
		if (dec > 0)

		x += p_data->step_x;
	}
}

void	draw_vertical(t_point *p_data, t_map *p1, t_map *p2, t_data *data)
{
	int	d_val;

	d_val = 2 * p_data->diff_x - p_data->diff_y;
}

int	comp_abs_val(t_point *p_data)
{
	if (p_data->diff_x >= p_data->diff_y)
		return (1);
	else
		return (0);
}

void	choose_line_path(t_point *p_data, t_map *p1, t_map *p2, )
{
	if (comp_abs_val(p_data) == 1)
		draw_horizontal();
	else if (comp_abs_val(p_data) == 0)
		draw_vertical();
}

void	choose_draw(t_map *p1, t_map *p2)
{
	t_point	*p_data;

	p_data = init_bresenham(p1, p2);
	choose_line_path(p_data, p1, p2);
}

t_point	*init_bresenham(t_map *p1, t_map *p2)
{
	t_point	*p_data;

	p_data = malloc(sizeof(t_point));
	if (!p_data)
		return ;
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
	next_p = find_next_point(current);
	if (next_p != NULL)
		choose_draw(current, next_p);
	sub_p = find_sub_point(current);
	if (sub_p != NULL)
		choose_draw(current, sub_p);
}

t_map	*find_next_point(t_map *current)
{
	t_map	*next_p;

	next_p = current->next;
	if (next_p->pos_y == current->pos_y && next_p->pos_x == current->pos_x + 30)
		return (next_p);
	return (NULL);
}

t_map	*find_sub_point(t_map *current)
{
	t_map	*iter;

	iter = current->next;
	while (iter)
	{
		if (iter->pos_x == current->pos_x && iter->pos_y == current->pos_y + 30)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
