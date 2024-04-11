/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:54 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/11 19:26:28 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* LIBFT INCLUDE */

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

/* MLX COMPATIBILITY */

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

/* DEFINITIONS */

	/* Window size */

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

	/* Key code and assignation */

# define KEY_W 119 // Move up
# define KEY_A 97 // Move left
# define KEY_S 115 // Move down
# define KEY_D 100 // Move right
# define KEY_Q 113 // Scale down
# define KEY_E 101 // Scale up
# define KEY_MINUS 45 // Projection down
# define KEY_PLUS 61 // Projection up
# define KEY_ESC 65307 // Exit

/* STRUCTURES */

	/* map data */

typedef struct s_map
{
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				x_scale;
	int				y_scale;
	int				color_code;

	int				save_x;
	int				save_y;
	int				save_z;

	struct s_map	*next;
}	t_map;

	/* Data and call */

typedef struct s_data
{
	struct s_map	*map_data;
	struct s_mlx	*mlx;
	struct s_img	*img;
	struct s_point	*p_data;
	struct s_mvt	*mvt;

	long int		col_nb;
	int				line_nb;
	int				standard_x;
	int				standard_y;
	int				index_x;
	int				index_y;
	t_map			*last;

}	t_data;

typedef struct s_mvt
{
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	int		offset_x;
	int		offset_y;
	int		add_x;
	int		add_y;
	int		projection;
	int		scale;
	float	zoom;
}	t_mvt;

	/* Minilibx data */

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}	t_mlx;

	/* image data */

typedef struct s_img
{
	void			*img_ptr;
	char			*img_addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}	t_img;

	/* point data */

typedef struct s_point
{
	int				step_x;
	int				step_y;
	int				diff_x;
	int				diff_y;
}	t_point;

/* FDF_DRAW */

	/* FdF_clear_draw.c */

void	ft_mlx_clear_window(t_data *data);

	/* FdF_isometric.c */

void	apply_isometric_projection(t_data *data);
void	save_modified_value(t_map *cur);
void	rotate_around_z_axis(t_map *cur);
void	rotate_around_x_axis(t_map *cur, t_data *data);

	/* FdF_offset.c */

void	add_offset(t_data *data);
void	get_offset(t_data *data);

	/* FdF_bresenham.c */

void	draw_horizontal(t_point *p_data, t_map *p1, t_map *p2, t_data *data);
void	draw_vertical(t_point *p_data, t_map *p1, t_map *p2, t_data *data);
void	choose_draw(t_map *p1, t_map *p2, t_data *data);
void	draw_grid(t_data *data);
t_point	*init_bresenham(t_map *p1, t_map *p2);

/* TESTS */

void	print_gnl(char *line);
void	print_split(char **arr);
void	print_map_data(t_map *map);
void	print_map_point(t_data *data);

/* FDF_UTILS */

	/* FdF_size_utils */

int		count_columns(const char *line, char c);
int		count_lines(char *file_name);

	/* FdF_list_utils.c */

t_map	*find_next_point(t_map *current, t_data *data);
t_map	*find_sub_point(t_map *current, t_data *data);

	/* FdF_bresenham_utils.c */

int		comp_abs_val(t_point *p_data);

	/* FdF_draw_utils.c */

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int		calculate_color_gradient(int p1, int p2, int perc);

	/* FdF_mvt_utils.c */

void	init_mvt(t_data *data);
void	apply_zoom_to_point(t_data *data, float zoom);

/* MLX_MANAGEMENT */

	/* Minilibx_creation.c */

t_mlx	*init_mlx(t_data *data);
void	init_mlx_image(t_data *data);
void	render(t_data *data);

	/* Minilibx_key_handling.c */

int		switch_assignment(int key_code, t_data *data);
void	apply_projection(int key_code, t_data *data);
void	apply_translation(int key_code, t_data *data);
void	apply_zoom(int key_code, t_data *data);
void	exit_using_key_esc(t_data *data);

/* FDF_PARSING */

	/* FdF_parsing.c */

int		open_file(char *file_name);
void	get_and_parse_the_line(char *file_name, t_data *data);
void	parse_the_line(char *line, t_data *data);
int		token_data_to_struct(char *token, t_data *data);
int		sub_token_data_to_struct(char *token, t_data *data);

	/* FdF_node_management.c */

void	assign_sub_token_data(char **sub_token, t_map *new_node, t_data *data);
void	assign_token_data(char *token, t_map *new_node, t_data *data);
void	append_node_at_tail(t_data *data, t_map *new_node);
void	get_original_map_data(t_data *data);

	/* FdF_memory_management.c */

void	free_map_struct(t_map *map_data);
void	free_and_quit_program(char *line, char **tokens, t_data *data);

/* FDF_ERROR */

	/* FdF_line_error.c */

int		check_line(char *line);
int		is_line_char_valid(char *line);
int		count_columns(const char *line, char c);

	/* FdF_token_error.c */

int		is_value_valid(char *value);
int		is_color_code_valid(char *color_code);

#endif
