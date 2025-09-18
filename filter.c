#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *pattern = av[1];
	int pattern_len = strlen(pattern);
	char c;
	int matched = 0;
	while (read(0, &c, 1))
	{
		if (c == pattern[matched])
		{
			matched++;
			if (matched == pattern_len)
			{
				for (int i = 0; i < pattern_len; i++)
					write(1, "*", 1);
				matched = 0;
			}
		}
		else
		{
			for (int i = 0; i < matched; i++)
				write(1, &pattern[i], 1);

			if (pattern[0] == c)
				matched = 1;
			else
			{
				write(1, &c, 1);
				matched = 0;
			}
		}
	}

	return (0);
}