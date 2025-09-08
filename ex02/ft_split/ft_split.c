#include <stdio.h>
#include <stdlib.h>

int	is_whitespace(char c)
{
	if (!c)
		return (0);
	if (c == 32 || (c <= 12 && c >= 9))
		return (1);
	return (0);
}

int	count_word(char *str)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int	i;
	int	word_count;
	int	len;
	char	**result;

	i = 0;
	len = 0;
	word_count = count_word(str);
	result = malloc(sizeof(char *) * (word_count + 1));
	while (i < word_count)
	{
		len = 0;
		while (is_whitespace(*str))
			str++;
		while (!is_whitespace(str[len]))
			len++;
		result[i] = malloc(len + 1);
		if (!result[i])
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return NULL;
		}
		result[i][len] = '\0';
		len = 0;
		while (!is_whitespace(*str))
		{
			result[i][len] = *str;
			str++;
			len++;
		}
		i++;
	}
	result[word_count] = NULL;
	return (result);
}

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split(" sad  dasda   ad       asdads asd");
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
