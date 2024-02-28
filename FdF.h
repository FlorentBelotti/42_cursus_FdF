/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:54 by fbelotti          #+#    #+#             */
/*   Updated: 2024/02/28 01:28:21 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../get_next_line/get_next_line.h"
# include "../get_next_line/get_next_line_bonus.h"

typedef struct s_data
{
	struct s_map	*map_data;

}	t_data;

typedef struct s_map
{
	int				pos_x;
	int				pos_y;
	int				pos_z;

	int				color_code;

	struct s_map	*next;
	struct s_map	*previous;
}	t_map;

#endif
