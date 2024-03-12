/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:01 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 18:27:24 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		write (2, "file is not found\n", 18);
	return (fd);
}

void	get_and_parse_the_line(char *file_name, t_data *data)
{
	char	*line;
	int		fd;

	fd = open_file(file_name);
	line = get_next_line(fd);
	data->col_nb = count_columns(line, ' ');
	data->standard_y = 1;
	while (line != NULL && check_line(line, data))
	{
		parse_the_line(line, data);
		free(line);
		data->standard_y += 1;
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse_the_line(char *line, t_data *data)
{
	char	**token;
	int		i;

	i = 0;
	token = ft_split(line, ' ');
	data->standard_x = 1;
	while (token[i])
	{
		if (there_is_a_comma(token[i]))
			sub_token_data_to_struct(token[i], data);
		else
			token_data_to_struct(token[i], data);
		data->standard_x += 1;
		i++;
	}
	ft_free_array(token);
}

void	token_data_to_struct(char *token, t_data *data)
{
	t_map	*new_node;
	t_map	*current;

	if (is_value_valid(token))
	{
		new_node = malloc(sizeof(t_map));
		if (!new_node)
			return ;
		assign_token_data(token, new_node, data);
		if (data->map_data == NULL)
			data->map_data = new_node;
		else
		{
			current = data->map_data;
			while (current->next)
				current = current->next;
			current->next = new_node;
		}
	}
}

void	sub_token_data_to_struct(char *token, t_data *data)
{
	char	**sub_token;
	t_map	*new_node;
	t_map	*current;

	sub_token = ft_split(token, ',');
	if (is_value_valid(sub_token[0]) && is_color_code_valid(sub_token[1]))
	{
		new_node = malloc(sizeof(t_map));
		if (!new_node)
			return ;
		assign_sub_token_data(sub_token, new_node, data);
		if (data->map_data == NULL)
			data->map_data = new_node;
		else
		{
			current = data->map_data;
			while (current->next)
				current = current->next;
			current->next = new_node;
		}
	}
	ft_free_array(sub_token);
}
