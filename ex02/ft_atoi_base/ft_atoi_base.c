#include <stdio.h>
#include <unistd.h>

int find_pos(char c)
{
	char *hex = "0123456789abcdef";
	char *hex_upper = "0123456789ABCDEF";

	int i = 0;
	while(i < 16)
	{
		if(hex[i] == c || hex_upper[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int val;

	if(*str == '-')
	{
		sign = -1;
		str++;
	}

	while(*str)
	{
		val = find_pos(*str);
		if(val < 0 || val >= str_base)
			break;
		result = result * str_base + val;
		str++;
	}
	
	return result * sign;
}

int main()
{
	printf("num - %d\n", ft_atoi_base("F1E8", 16));
	return (0);
}
