#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *join(char *dest, char *src)
{
	int j = 0;
	while (src[j])
		j++;
	if (j == 0)
		return (dest);
	while (dest && dest[j])
		j++;
	char *result;
	result = malloc(j + 1);
	j = 0;
	while (dest && dest[j])
	{
		result[j] = dest[j];
		j++;	
	}
	if (j > 0)
		free(dest);
	int i = 0;
	while (src[i])
	{
		result[j] = src[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

void print(char *str, char *except)
{
	if (!str)
		return;
	int i = 0;
	int j;
	while (str[i])
	{
		j = 0;
		while (except[j] && str[i + j] == except[j])
		{
			j++;
		}
		if (!except[j])
		{
			int until = i + j;
			while (i < until)
			{
				printf("%c", '*');
				i++;
			}
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	char buf[20];
	char *str_in = NULL;
	int readed = 1;
	while (readed > 0)
	{
		readed = read(0, buf, 19);
		if (readed == -1)
		{
			free(str_in);
			return (1);
		}
		buf[readed] = '\0';
		str_in = join(str_in, buf);
	}
	print(str_in, argv[1]);
	free(str_in);
	return (0);
}

