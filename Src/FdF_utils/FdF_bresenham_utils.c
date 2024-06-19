/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_bresenham_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:54:18 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

int comp_abs_val(t_point *p_data)
{
	if (p_data->diff_x >= p_data->diff_y)
		return (1);
	else
		return (0);
}
