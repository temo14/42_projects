#include <unistd.h>

int atoi(char *str)
{
	int result = 0;
	while(*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return result;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int num = atoi(argv[1]);
	char *hex = "0123456789abcdef";
	char buffer[100];
	int i = 0;
	while(num > 0)
	{
		buffer[i++] = hex[num % 16];
		num /= 16;
	}
	while(i--)
		write(1, &buffer[i], 1);

	write(1, "\n", 1);
	return 0;
}
