#include <stdio.h>
#include <stdlib.h>

int		n;
int		*nums;
int		*subset;
int		target;

void	print_subset(int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", subset[i]);
	printf("\n");
}

void	solve(int pos, int size, int sum)
{
	if (pos == n)
	{
		if (sum == target)
			print_subset(size);
		return ;
	}
	solve(pos + 1, size, sum);
	subset[size] = nums[pos];
	solve(pos + 1, size + 1, sum + nums[pos]);
}

int	main(int ac, char *av[])
{
	nums = malloc((ac - 1) * sizeof(int));
	subset = malloc((ac - 1) * sizeof(int));
	target = atoi(av[1]);
	n = ac - 2;
	for (int i = 0; i < n; i++)
		nums[i] = atoi(av[i + 2]);
	solve(0, 0, 0);
	free(nums);
	free(subset);
	return (0);
}