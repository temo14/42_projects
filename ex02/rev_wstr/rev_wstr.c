#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_whitespace_or_end(char c)
{
	if (!c)
		return (1);
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	rev_wstr(char *str)
{
	int	len;
	int	end;
	int	start;
	int	first_word;

	if (!str)
		return ;
	len = str_len(str);
	end = len - 1;
	first_word = 1;
	while (end >= 0 && is_whitespace_or_end(str[end]))
		end--;
	while (end >= 0)
	{
		start = end;
		while (start >= 0 && !is_whitespace_or_end(str[start]))
			start--;
		start++;
		if (!first_word)
			write(1, " ", 1);
		write(1, &str[start], end - start + 1);
		first_word = 0;
		end = start - 1;
		while (end >= 0 && is_whitespace_or_end(str[end]))
			end--;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rev_wstr(argv[1]);
	return (0);
}