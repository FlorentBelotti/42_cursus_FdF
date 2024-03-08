/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:54 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/08 16:39:06 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	struct s_map	*map_data;

	int				standard_x;
	int				standard_y;
	int				col_nb;
	int				line_nb;

}	t_data;

typedef struct s_map
{
	int				pos_x;
	int				pos_y;
	int				pos_z;
	unsigned int	color_code;

	struct s_map	*next;
}	t_map;

/* Tests */

void	print_gnl(char *line);
void	print_split(char **arr);

/* FdF_parsing */

int		open_file(char *file_name);
char	*get_next_line(int fd);
void	get_and_parse_the_line(char *file_name, t_data *data);
void	parse_the_line(char *line, t_data *data);

/* FdF_line_error */

int		check_line(char *line, t_data *data);
int		is_col_nb_equal(char *line, t_data *data);
int		is_line_char_valid(char *line);
int		count_columns(const char *line, char c);
char	*ft_strchr(const char *s, int c);

/* FdF_split */

int		count_words(const char *s, char c);
int		word_length(const char *s, char c);
char	*extract_word(const char *s, int word_len);
char	**free_split(char **arr);
char	**ft_split(char const *s, char c);

#endif
