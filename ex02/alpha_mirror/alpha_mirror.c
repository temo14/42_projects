#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	char *str = argv[1];
	char c;
	while(*str)
	{
		c = *str;
		if(*str >= 'a' && *str <= 'z')
		{
			c = 'z' - (*str - 'a');
		}	
		if(*str >= 'A' && *str <= 'Z')
                {
			c = 'Z' - (*str - 'A');
                }
		write(1, &c, 1);
		str++;
	}
	return 0;
}
