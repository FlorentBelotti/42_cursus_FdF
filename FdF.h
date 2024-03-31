/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:54 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/29 18:20:33 by fbelotti         ###   ########.fr       */
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
# define KEY_ESC 65307 // Exit

/* STRUCTURES */

	/* Data and call */

typedef struct s_data
{
	struct s_map	*map_data;
	struct s_mlx	*mlx;
	struct s_img	*img;
	struct s_point	*p_data;

	long int		col_nb;
	int				line_nb;
	int				standard_x;
	int				standard_y;

}	t_data;

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
	char			*img_pxl_ptr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}	t_img;

	/* map data */

typedef struct s_map
{
	int				pos_x;
	int				pos_y;
	int				pos_z;
	unsigned int	color_code;

	struct s_map	*next;
}	t_map;

	/* point data */

typedef struct s_point
{
	int				step_x;
	int				step_y;
	int				diff_x;
	int				diff_y;
}	t_point;

/* TESTS */

void	print_gnl(char *line);
void	print_split(char **arr);
void	print_map_data(t_map *map);
void	print_map_point(t_data *data);

t_map	*find_sub_point(t_map *current);

/* FDF_UTILS */

	/* FdF_size_utils */

int		count_columns(const char *line, char c);
int		count_lines(char *file_name);

/* MLX_MANAGEMENT */

	/* Minilibx_creation.c */

t_mlx	*init_mlx(t_data *data);
t_img	*init_mlx_image(t_data *data);
void	render(t_data *data);

	/* Minilibx_key_handling.c */

void	exit_using_key_esc(t_data *data);
int		switch_assignment(int key_code, t_data *data);

	/* Minilibx_drawing.c */

void	drawing_grid(t_data *data);

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

	/* FdF_memory_management.c */

void	free_all(t_data *data);
void	free_map_struct(t_map *map_data);
void	free_and_quit_program(char *line, char **tokens, t_data *data);

/* FDF_ERROR */

	/* FdF_line_error.c */

int		check_line(char *line, t_data *data);
int		is_col_nb_equal(char *line, t_data *data);
int		is_line_char_valid(char *line);
int		count_columns(const char *line, char c);

	/* FdF_token_error.c */

int		is_value_valid(char *value);
int		is_color_code_valid(char *color_code);

#endif
