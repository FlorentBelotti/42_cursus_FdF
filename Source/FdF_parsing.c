/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:01 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/08 16:38:46 by fbelotti         ###   ########.fr       */
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
	while (line != NULL && check_line(line, data))
	{
		parse_the_line(line, data);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse_the_line(char *line, t_data *data)
{
	char	**tokens;
	(void) data;

	tokens = ft_split(line, ' ');
	print_split(tokens);
}


