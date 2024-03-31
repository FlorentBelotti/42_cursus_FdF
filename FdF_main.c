/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:33:38 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/29 18:20:35 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*current;

	if (ac != 2)
		return (0);
	data.map_data = NULL;
	get_and_parse_the_line(av[1], &data);
	/*data.mlx = init_mlx(&data);
	data.img = init_mlx_image(&data); */
	free_all(&data);
}

