/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_Size_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:23:48 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/28 10:25:31 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	count_columns(const char *line, char c)
{
	int	i;
	int	col_count;

	i = 0;
	col_count = 0;
	while (line[i])
	{
		while (line[i] == c)
			i++;
		if (line[i])
			col_count++;
		while (line[i] && line[i] != c)
			i++;
	}
	return (col_count);
}

int	count_lines(char *file_name)
{
	int		fd;
	int		line_nb;
	char	*line;

	line = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_nb);
}
