#include "push_swap.h"

int str_len(char  *s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

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

// int isNumber(char *number)
// {
//     int i = 0;

//     //checking for negative numbers
//     if (number[0] == '-')
//         i = 1;
//     while (number[i] != 0)
//     {
//         // if (number[i] > '9' || number[i] < '0')
//         if (!ft_isdigit(number[i]))
//             return 0;
//     }
//     return 1;
// }

int		ft_isspace(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}


t_bool	isNumber(const char *str, t_bool strict)
{
	unsigned int	result;
	unsigned int	border;
	int				i;
	int				sign;
	int				digits;

	result = 0;
	digits = 0;
	border = (unsigned int)(FT_INT_MAX / 10);
	i = 0;
	while (!strict && ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((result > border || (result == border && (str[i] - '0') > 7))
				&& sign == 1)
			|| ((result > border || (result == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (false);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}