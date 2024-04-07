/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_token_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:35:55 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/07 13:19:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	is_value_valid(char *value)
{
	int	i;

	i = 0;
	/*if (ft_atoi(value) == 0 && ft_strcmp("0", value))
	{
		write (2, "ERROR : value out of bond\n", 26);
		return (0);
	}*/
	if (value[0] == '-')
		i++;
	if (value[i] == '\0')
		return (0);
	while (value[i])
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '\n')
		{
			write (2, "ERROR : Invalid value definition in map\n", 40);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_color_code_valid(char *color_code)
{
	int	i;

	if (color_code[0] != '0' || (color_code[1] != 'x' && color_code[1] != 'X'))
	{
		write (2, "ERROR : Invalid color code\n", 27);
		return (0);
	}
	i = 2;
	while (ft_ishex(color_code[i]) == 1)
		i++;
	if (i > 8)
	{
		write (2, "ERROR : Invalid color code\n", 27);
		return (0);
	}
	return (1);
}
