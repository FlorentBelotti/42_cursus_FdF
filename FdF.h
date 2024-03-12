/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:54 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 18:25:43 by fbelotti         ###   ########.fr       */
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

/* Tests */

void	print_gnl(char *line);
void	print_split(char **arr);
void	print_map_data(t_map *map);

/* FdF_parsing */

int		open_file(char *file_name);
void	get_and_parse_the_line(char *file_name, t_data *data);
void	parse_the_line(char *line, t_data *data);
void	token_data_to_struct(char *token, t_data *data);
void	sub_token_data_to_struct(char *token, t_data *data);

/* FdF_data_fill */

void	assign_sub_token_data(char **sub_token, t_map *new_node, t_data *data);
void	assign_token_data(char *token, t_map *new_node, t_data *data);

/* FdF_line_error */

int		check_line(char *line, t_data *data);
int		is_col_nb_equal(char *line, t_data *data);
int		is_line_char_valid(char *line);
int		count_columns(const char *line, char c);

/* FdF_token_error */

int		there_is_a_comma(char *token);
int		is_value_valid(char *value);
int		is_color_code_valid(char *color_code);

#endif
