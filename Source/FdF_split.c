/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:14:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/08 16:33:18 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word_count);
}

int	word_length(const char *s, char c)
{
	int	word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
	{
		word_len++;
	}
	return (word_len);
}

char	*extract_word(const char *s, int word_len)
{
	int		i;
	char	*word_extract;

	i = 0;
	word_extract = (char *)malloc(word_len + 1);
	if (!word_extract)
		return (NULL);
	while (i < word_len)
	{
		word_extract[i] = s[i];
		i++;
	}
	word_extract[i] = '\0';
	return (word_extract);
}

char	**free_split(char **arr)
{
	int	i;

	i = 0 ;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**arr;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (s[i++] != c)
		{
			len = word_length(&s[i - 1], c);
			arr[j] = extract_word(&s[i - 1], len);
			if (!arr[j])
				return (free_split(arr));
			i += len - 1;
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
