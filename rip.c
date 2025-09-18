#include <stdio.h>

int	is_valid(char *s)
{
	int	i;
	int	bal;

	i = 0;
	bal = 0;
	while (s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
		{
			if (bal <= 0)
				return (0);
			bal--;
		}
		i++;
	}
	return (bal == 0);
}
void	solve(char *str, int start, int lrem, int rrem)
{
	char	temp;

	if (lrem == 0 && rrem == 0)
	{
		if (is_valid(str))
			puts(str);
		return ;
	}
	for (int i = start; str[i]; i++)
	{
		if (str[i] != '(' && str[i] != ')')
			continue ;
		temp = str[i];
		str[i] = ' ';
		if (temp == '(' && lrem > 0)
			solve(str, i + 1, lrem - 1, rrem);
		else if (temp == ')' && rrem > 0)
			solve(str, i + 1, lrem, rrem - 1);
		str[i] = temp;
	}
}

int	main(int ac, char **av)
{
	int lrem = 0, rrem = 0;
	char *str = av[1];
	int i = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			lrem++;
		}
		else if (str[i] == ')')
		{
			if (lrem > 0)
				lrem--;
			else
				rrem++;
		}
		i++;
	}
	solve(str, 0, lrem, rrem);
	return (0);
}