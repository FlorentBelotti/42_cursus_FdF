/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_memory_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:51 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/11 23:30:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	free_and_quit_program(char *line, char **tokens, int fd, t_data *data)
{
	if (data->map_data != NULL)
		free_map_struct(data->map_data);
	ft_free_array(tokens);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free(data->mvt);
	exit (0);
}

void	free_map_struct(t_map *map_data)
{
	t_map	*current;
	t_map	*next;

	current = map_data;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
