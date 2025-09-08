#include <unistd.h>

int is_member(char c)
{
	if((c >= 8 && c <= 13) || c == ' ' || !c)
		return 0;	
	return 1;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	char *str = argv[1];
	
	while(!is_member(str[i]))
		i++;

	while(is_member(str[i]))
	{
		write(1, &str[i], 1);
		i++;	
	}
	return 0;
}
