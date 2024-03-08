/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_line_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:51:16 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/08 15:59:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	check_line(char *line, t_data *data)
{
	if (is_col_nb_equal(line, data) && is_line_char_valid(line))
		return (1);
	else
		return (0);
}

int	is_col_nb_equal(char *line, t_data *data)
{
	int	curr_col_nb;

	curr_col_nb = count_columns(line, ' ');
	if (curr_col_nb == data->col_nb)
		return (1);
	else
		return (0);
}

int	is_line_char_valid(char *line)
{
	const char	*valid_chars;
	int			i;

	valid_chars = "0123456789ABCDEFabcdefx,-+ \n\0";
	i = 0;
	while (line[i])
	{
		if (ft_strchr(valid_chars, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
