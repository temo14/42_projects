#include <stdio.h>

void	solve(char *str, int pos, int left_rem, int right_rem, int balance)
{
	char	current;

	if (str[pos] == '\0')
	{
		if (left_rem == 0 && right_rem == 0 && balance == 0)
			puts(str);
		return ;
	}
	current = str[pos];
	if (current == '(')
	{
		if (left_rem > 0)
		{
			str[pos] = ' ';
			solve(str, pos + 1, left_rem - 1, right_rem, balance);
			str[pos] = '(';
		}
		solve(str, pos + 1, left_rem, right_rem, balance + 1);
	}
	else if (current == ')')
	{
		if (right_rem > 0)
		{
			str[pos] = ' ';
			solve(str, pos + 1, left_rem, right_rem - 1, balance);
			str[pos] = '(';
		}
		if (balance > 0)
			solve(str, pos + 1, left_rem, right_rem, balance - 1);
	}
	else
	{
		solve(str, pos + 1, left_rem, right_rem, balance);
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (1);
	char *str = av[1];
	int left_to_remove = 0;
	int right_to_remove = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			left_to_remove++;
		}
		else if (str[i] == ')')
		{
			if (left_to_remove > 0)
				left_to_remove--;
			else
				right_to_remove++;
		}
		i++;
	}
	solve(str, 0, left_to_remove, right_to_remove, 0);
	return (0);
}