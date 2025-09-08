#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
		return(0);

	char c;
	char *str = argv[1];
	while(*str)
	{
		c = *str;
		if(c >= 'A' && c <= 'Z')
		{
			write(1, "_", 1);
			c = c + 32;
		}
		write(1, &c, 1);
		str++;
	}

	return (0);
}
