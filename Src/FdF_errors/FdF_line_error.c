/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_line_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:51:16 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

int check_line(char *line)
{
	if (is_line_char_valid(line))
		return (1);
	else
		return (0);
}

int is_line_char_valid(char *line)
{
	const char *valid_chars;
	int i;

	valid_chars = "0123456789ABCDEFabcdefx,-+ \n\0";
	i = 0;
	while (line[i])
	{
		if (ft_strchr(valid_chars, line[i]) == NULL)
		{
			write(2, "ERROR : invalid character in line\n", 34);
			return (0);
		}
		i++;
	}
	return (1);
}

void free_gnl_then_quit(char *line, int fd, t_data *data)
{
	if (data->map_data != NULL)
		free_map_struct(data->map_data);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	free(data->mvt);
	exit(EXIT_FAILURE);
}
