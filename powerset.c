#include <stdio.h>
#include <stdlib.h>

int		target;
int		n;
int		*numbers;
int		*sub_set;

void	print_result(int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		printf("%d ", sub_set[i]);
		i++;
	}
	printf("\n");
}

void	solve(int currentIndex, int subsetSize, int sum)
{
	if (currentIndex == n)
	{
		if (sum == target)
			print_result(subsetSize);
		return ;
	}
	solve(currentIndex + 1, subsetSize, sum);
	sub_set[subsetSize] = numbers[currentIndex];
	solve(currentIndex + 1, subsetSize + 1, sum + sub_set[subsetSize]);
}

int	main(int ac, char **av)
{
	target = atoi(av[1]);
	n = ac - 2;
	numbers = malloc(n * sizeof(int));
	sub_set = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		numbers[i] = atoi(av[i + 2]);
	solve(0, 0, 0);
	free(numbers);
	free(sub_set);
	return (0);
}