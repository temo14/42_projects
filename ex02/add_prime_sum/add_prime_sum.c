#include <unistd.h>
#include <stdio.h>

int atoi(char *str)
{
	int result = 0;

	while(*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

void put_nbr(int num)
{
	if(num >= 10)
		put_nbr(num / 10);
	
	int n = num % 10;
	char c = (char)n + '0';
	write(1, &c, 1);
}

int is_prime(int num)
{
	if(num < 2)
		return (0);
	int i = 2;
	while(i < num)
	{
		if(num % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "0\n", 1);
		return (0);
	}

	int num = atoi(argv[1]);
	int result = 0;
	int i = 2; 
	while(i <= num)
	{
		if(is_prime(i))
		{
		       result += i;
		}
		i++;	
	}
	put_nbr(result);
	write(1, "\n", 1);
	return(0);
}
