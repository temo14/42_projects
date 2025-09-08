#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int temp = 0;
	while(i < size - 1)
	{
		if(tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int main()
{
	int arr[5] = {2, 3, 1, 6, 4};
	sort_int_tab(arr, 5);
	int i = 0;

	while(i < 5)
	{
		printf("%d ,", arr[i]);
		i++;
	}

	return (0);
}
