/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_main_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:33:38 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/11 18:28:48 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.map_data = NULL;
	if (ac == 2)
	{
		get_and_parse_the_line(av[1], &data);
		print_map_data(data.map_data);
	}
}

void	print_gnl(char *line)
{
	int	i;

	i = 0;
	write (1, "gnl_line :", 10);
	while (line[i++])
		write (1, &line[i], 1);
}

void	print_split(char **arr)
{
	int	i = 0;
	int	j = 0;
	int	token_nb = 1;

	while (arr[j])
	{
		if (token_nb == 1)
			printf("\t\033[31m---- New_line ----\033[0m\n\n");
		i = 0;
		printf("\033[32m\tToken n°%d :\t \033[37m", token_nb);
		while (arr[j][i])
		{
			printf("%c", arr[j][i]);
			i++;
		}
		printf("\033[0m\n");
		j++;
		token_nb++;
	}
}

void	print_map_data(t_map *map)
{
	t_map *current = map;

	while (current)
	{
		printf("\t---- Noeud ----\n\n");
		printf("\t\033[31mPosition X : %d\033[0m\n", current->pos_x);
		printf("\t\033[31mPosition Y : %d\033[0m\n", current->pos_y);
		printf("\t\033[31mPosition Z : %d\033[0m\n", current->pos_z);
		printf("\033[32m\tColor_code : %#X\033[37m\n\n", current->color_code);
		current = current->next;
	}
}
