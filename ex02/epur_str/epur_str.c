#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *str = argv[1];
	int is_word = 0;
	while(*str)
	{
		if(*str == ' ' || (*str >= 9 && *str <= 13))
		{
			if(is_word && *(str++))
			{
				write(1, " ", 1);
				is_word = 0;
			}
		}
		else
		{
			write(1, str, 1);
			is_word = 1;
		}
		str++;
	}
	write(1, "\n", 1);

	return 0;
}
