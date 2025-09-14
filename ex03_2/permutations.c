#include <stdio.h>

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	permutate(char *str, int start, int end)
{
	if (start == end)
	{
		puts(str);
		return ;
	}
	for (int i = start; i < end; i++)
	{
		swap(&str[start], &str[i]);
		permutate(str, start + 1, end);
		swap(&str[start], &str[i]);
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (1);
	char *str = av[1];
	for (int i = 0; str[i]; i++)
		for (int j = 0; str[j + i]; j++)
			if (str[i] > str[i + j])
				swap(&str[i], &str[i + j]);
	int len = 0;
	for (int i = 0; str[i]; i++)
		len++;
	permutate(str, 0, len);
	return (0);
}