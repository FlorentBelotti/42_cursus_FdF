/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:27:35 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/11 18:10:49 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '+' || str[i] == ' ')
		i++;
	while (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + str[i] - '0';
		i++;
	}
	result = result * sign;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return ((int)result);
}

int	fdf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_strtol(const char *color_code)
{
	long	res;
	int		i;

	i = 2;
	res = 0;
	while (color_code[i])
	{
		res *= 16;
		if (is_digit(color_code[i]))
			res += color_code[i] - '0';
		else if (color_code[i] >= 'A' && color_code[i] <= 'F')
			res += 10 + (color_code[i] - 'A');
		else if (color_code[i] >= 'a' && color_code[i] <= 'f')
			res += 10 + (color_code[i] - 'a');
		i++;
	}
	return (res);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	free_split_token(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
