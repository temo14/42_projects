#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char *argv[])
{
	char *str;
	int i, is_first, first_index, printed;

	if (argc < 2)
		return (write(1, "\n", 1));

	str = argv[1];
	i = 0;
	is_first = 1;
	first_index = 0;
	printed = 0;

	while (is_space(str[i]))
		i++;
	if (!str[i])
		return (write(1, "\n", 1));

	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (!str[i])
			break ;

		if (is_first)
		{
			is_first = 0;
			first_index = i;
			while (str[i] && !is_space(str[i]))
				i++;
			continue ;
		}

		if (printed && i > 0 && is_space(str[i - 1]))
			write(1, " ", 1);
		write(1, &str[i], 1);
		printed = 1;
		i++;
	}

	if (printed)
		write(1, " ", 1);
	while (!is_space(str[first_index]) && str[first_index])
	{
		write(1, &str[first_index], 1);
		first_index++;
	}

	write(1, "\n", 1);
	return (0);
}