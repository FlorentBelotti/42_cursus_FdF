/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_node_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:58:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/07 16:48:17 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	assign_sub_token_data(char **sub_token, t_map *new_node, t_data *data)
{
	new_node->pos_z = ft_atoi(sub_token[0]);
	new_node->color_code = ft_strtol(sub_token[1]);
	new_node->pos_x = data->standard_x;
	new_node->pos_y = data->standard_y;
	new_node->save_x = data->standard_x;
	new_node->save_y = data->standard_y;
	new_node->next = NULL;
}

void	assign_token_data(char *token, t_map *new_node, t_data *data)
{
	new_node->pos_z = ft_atoi(token);
	new_node->color_code = 0xFFFFFF;
	new_node->pos_x = data->standard_x;
	new_node->pos_y = data->standard_y;
	new_node->save_x = data->standard_x;
	new_node->save_y = data->standard_y;
	new_node->next = NULL;
}

void	append_node_at_tail(t_data *data, t_map *new_node)
{
	t_map	*current;

	current = data->map_data;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
