/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:44:36 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 03:44:42 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c || *s == '\n')
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	*get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void	*free_words(char **words, size_t i)
{
	while (i--)
	{
		if (words && words[i])
		{
			free(words[i]);
			words[i] = NULL;
		}
	}
	free(*words);
	return (NULL);
}

static char	**get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	words = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (words)
	{
		i = 0;
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s == 0)
				break ;
			word = get_word(s, c);
			if (!word)
				return (free_words(words, i));
			words[i++] = word;
			s += (str_len(word) + 1);
		}
		words[i] = NULL;
	}
	return (words);
}

char	**ft_split(char const *s, char c, int *items_count)
{
	char	**words;
	char	*line;
	int		wc;

	if (!s)
		return (NULL);
	line = ft_strdup(s);
	if (!line)
		return (NULL);
	wc = count_words(line, c);
	words = get_words(line, c, wc);
	if (items_count)
		*items_count = wc;
	free(line);
	return (words);
}
