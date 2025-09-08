int main(int argc, char *argv[])
{
	char *str1 = argv[1];
	char *str2 = argv[2];
	int i = 0;
	char table[256] = {0};

	while (str1[i])
	{
		if (!table[str1[i]])
		{
			table[str1[i]] = str1[i];
			write(1, &str1[i], 1);
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (!table[str2[i]])
		{
			table[str2[i]] = str2[i];
			write(1, &str2[i], 1);
		}
		i++;
	}
	return (0);
}
