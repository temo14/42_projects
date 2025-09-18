#include <stdio.h>

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	solve(char *str, int pos, int len)
{
	if (pos == len)
	{
		puts(str);
		return ;
	}
	for (int i = pos; i < len; i++)
	{
		swap(&str[i], &str[pos]);
		solve(str, pos + 1, len);
		swap(&str[i], &str[pos]);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *str = av[1];
	int len = 0;
	for (; str[len]; len++)
		for (int i = 0; str[i + 1]; i++)
			if (str[i] > str[i + 1])
				swap(&str[i], &str[i + 1]);
	solve(str, 0, len);
	return (0);
}