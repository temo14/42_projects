#include <stdlib.h>

int is_space(char c)
{
	if(c == ' ' || c >= 9 && c <= 12)
		return 1;
	return 0;
}

int count_word(char *str)
{
	int i = 0;
	int counted = 0;
	int count = 0;
	while(str[i])
	{
		if(!is_space(str[i]))
		{
			if(counted == 0)
			{
				counted = 1;
				count++;
			}
		} 
		if(is_space(str[i]))
		{
			counted = 0;
		}
		i++;
	}
	return count;
}

char *extract(char **s)
{
	char *str = *s;
	int i = 0;
	while (is_space(*str))
		str++;
	while (!is_space(str[i]))
		i++;
	char *result = malloc(i + 1);
	result[i] = '\0';
	i = 0;
	while(!is_space(*str))
	{
		result[i] = *str;
		str++;
		i++;
	}
	*s = str;
	return result;
}

char    **ft_split(char *str)
{
	int count = count_word(str);
	char **result = malloc(sizeof(char *) * (count + 1));
	int i = 0;
	result[count] = NULL;
	while (i < count)
	{
		result[i] = extract(&str);
		i++;
	}
	return result;
}

int main()
{
	char **res = ft_split(" asd  asdas sa  s ");
	while(*res)
	{
		printf("%s\n", *res);
		res++;
	}
	return (0);
}
