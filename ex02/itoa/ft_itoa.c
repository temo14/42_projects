#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
	int i = 0;
	int sign = 1;
	if(nbr < 0)
	{
		i++;
		sign = -1;
	}
	int num = nbr;
	while(nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	char *result = malloc(i + 1);
	if(sign == -1)
	{
		result[0] = '-';
		num = -num;
	}
	result[i] = '\0';
	
	while(i > 0)
	{
		i--;
		if(i == 0 && sign == -1)
			break;
		result[i] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

int main()
{
	printf("%s\n", ft_itoa(-110));
	return (0);
}
