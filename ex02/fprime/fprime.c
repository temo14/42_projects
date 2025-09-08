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
	return result;
}

int is_prime(int n)
{
	if(n <= 1)
		return (0);

	int i = 2;
	while(i * i <= n)
	{
		if(n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void put_nbr(int num)
{
	if(num >= 10)
		put_nbr(num / 10);
	char c = (num % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	int num = atoi(argv[1]);
	if (num == 1)
	{
		put_nbr(1);
		write(1, "\n", 1);
		return 0;
	}
	int i = 2;
	int first = 1;
	while(i <= num)
	{
		if(is_prime(i))
		{
			if(num % i == 0)
			{
				num /= i;
				if(!first)
					write(1, "*", 1);
				put_nbr(i);
				first = 0;
				continue;
			}
		}
		i++;
	}
	return (0);
}
