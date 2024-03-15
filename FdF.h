/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:54 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/14 18:56:40 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"

typedef struct s_data
{
	struct s_map	*map_data;

	int				standard_x;
	int				standard_y;
	long int		col_nb;
	int				line_nb;

}	t_data;

typedef struct s_map
{
	int				pos_x;
	int				pos_y;
	int				pos_z;
	unsigned int	color_code;

	struct s_map	*next;
}	t_map;

/* TESTS */

void	print_gnl(char *line);
void	print_split(char **arr);
void	print_map_data(t_map *map);

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

void	free_all_struct(t_data *data);
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
