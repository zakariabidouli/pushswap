#include "push_swap.h"

void	split_free(char ***strsplit)
{
	char	**current;

	if (strsplit && *strsplit)
	{
		current = ((*strsplit));
		while ((*current))
			free((*(current++)));
		free((*strsplit));
		(*strsplit) = NULL;
	}
}

int str_len(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static size_t count_words(char const *s, char c)
{
	size_t words;

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

static char *get_word(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void *free_words(char **words, size_t i)
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

static char **get_words(char *s, char c, size_t words_count)
{
	char **words;
	char *word;
	size_t i;

	words = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (words)
	{
		i = 0;
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s == 0)
				break;
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

char **ft_split(char const *s, char c, int *items_count)
{
	char **words;
	char *line;
	int wc;

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

int ft_isspace(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

t_bool is_int(const char *str, t_bool strict)
{
	unsigned int result;
	unsigned int border;
	int i;
	int sign;
	int digits;

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
		if (((result > border || (result == border && (str[i] - '0') > 7)) && sign == 1) || ((result > border || (result == border && (str[i] - '0') > 8)) && sign == -1))
			return (false);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}

t_bool is_num(char *str)
{
	size_t i;
	size_t digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]) >= 0 && str[i])
	{
		i++;
		digits++;
	}
	if (!str[i] && digits)
		return (true);
	return (false);
}

// int		ft_islower(int c)
// {
// 	return (c >= 'a' && c <= 'z');
// }

// int		ft_toupper(int c)
// {
// 	return (ft_islower(c) ? (c - 'a' + 'A') : c);
// }

// int		ft_isdigit_base(char c, int base)
// {
// 	const char	*digits = "0123456789ABCDEF";
// 	int			i;

// 	i = 0;
// 	while (i < base)
// 	{
// 		if (ft_toupper(c) == digits[i])
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// t_bool	ft_isprefix(const char *str, int base)
// {
// 	size_t	i;

// 	i = 0;
// 	if (base == 2 || base == 8 || base == 16)
// 	{
// 		if (str[i++] != '0')
// 			return (false);
// 		if (base == 2 && (ft_toupper(str[i]) == 'B'))
// 			return (true);
// 		if (base == 16 && (ft_toupper(str[i]) == 'X'))
// 			return (true);
// 		if (base == 8)
// 			return (true);
// 	}
// 	return (false);
// }

// t_bool	is_num(char *str, int base)
// {
// 	size_t	i;
// 	size_t	digits;

// 	i = 0;
// 	digits = 0;
// 	while (ft_isspace(str[i]))
// 		i++;
// 	if (base != 10 && !ft_isprefix(&str[i], base))
// 		return (false);
// 	if (base == 2 || base == 16)
// 		i += 2;
// 	else if (base == 8)
// 		i++;
// 	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
// 		i++;
// 	while (ft_isdigit_base(str[i], base) >= 0)
// 	{
// 		i++;
// 		digits++;
// 	}
// 	return ((!str[i] && digits) ? true : false);
// }