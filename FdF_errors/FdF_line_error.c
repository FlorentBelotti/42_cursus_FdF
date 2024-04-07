/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_line_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:51:16 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/07 13:15:18 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	check_line(char *line)
{
	if (is_line_char_valid(line))
		return (1);
	else
		exit (0);
}

/* int	is_col_nb_equal(char *line, t_data *data)
{
	int	curr_col_nb;

	curr_col_nb = count_columns(line, ' ');
	if (curr_col_nb == data->col_nb)
		return (1);
	else
	{
		write (2, "ERROR : incorrect map shape\n", 28);
		return (0);
	}
} */

int	is_line_char_valid(char *line)
{
	const char	*valid_chars;
	int			i;

	valid_chars = "0123456789ABCDEFabcdefx,-+ \n\0";
	i = 0;
	while (line[i])
	{
		if (ft_strchr(valid_chars, line[i]) == NULL)
		{
			write (2, "ERROR : invalid character in line\n", 34);
			return (0);
		}
		i++;
	}
	return (1);
}
