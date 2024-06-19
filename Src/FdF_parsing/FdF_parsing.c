/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:01 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

int open_file(char *file_name, t_data *data)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
	{
		perror("ERROR : while opening file");
		free(data->mvt);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void get_and_parse_the_line(char *file_name, t_data *data)
{
	char *line;
	int fd;

	fd = open_file(file_name, data);
	line = get_next_line(fd);
	data->col_nb = count_columns(line, ' ');
	data->line_nb = count_lines(file_name);
	data->standard_y = 1;
	data->index_y = 1;
	while (line != NULL)
	{
		if (check_line(line))
		{
			parse_the_line(line, fd, data);
			free(line);
			data->standard_y += data->mvt->scale;
			data->index_y++;
			line = get_next_line(fd);
		}
		else
			free_gnl_then_quit(line, fd, data);
	}
	close(fd);
}

void parse_the_line(char *line, int fd, t_data *data)
{
	char **tokens;
	int i;

	i = 0;
	tokens = ft_split(line, ' ');
	data->standard_x = 1;
	data->index_x = 1;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], ','))
		{
			if (sub_token_data_to_struct(tokens[i], data) == 0)
				free_and_quit_program(line, tokens, fd, data);
		}
		else
		{
			if (token_data_to_struct(tokens[i], data) == 0)
				free_and_quit_program(line, tokens, fd, data);
		}
		data->standard_x += data->mvt->scale;
		data->index_x++;
		i++;
	}
	ft_free_array(tokens);
}

int token_data_to_struct(char *token, t_data *data)
{
	t_map *new_node;

	if (is_value_valid(token))
	{
		new_node = malloc(sizeof(t_map));
		if (!new_node)
			return (0);
		assign_token_data(token, new_node, data);
		if (data->map_data == NULL)
			data->map_data = new_node;
		else
			append_node_at_tail(data, new_node);
		data->last = new_node;
		return (1);
	}
	return (0);
}

int sub_token_data_to_struct(char *token, t_data *data)
{
	char **sub_token;
	t_map *new_node;

	sub_token = ft_split(token, ',');
	if (is_value_valid(sub_token[0]) && is_color_code_valid(sub_token[1]))
	{
		new_node = malloc(sizeof(t_map));
		if (!new_node)
			return (0);
		assign_sub_token_data(sub_token, new_node, data);
		if (data->map_data == NULL)
			data->map_data = new_node;
		else
			append_node_at_tail(data, new_node);
		data->last = new_node;
		ft_free_array(sub_token);
		return (1);
	}
	else
	{
		ft_free_array(sub_token);
		return (0);
	}
}
